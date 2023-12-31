#include <bits/stdc++.h>
#include "Operations.cpp"
using namespace std;

class mathObject{
	private:
		string type;
		double num;
		int pri;
	public:
		mathObject(string type = "", int pri = -1, double num = 0){
			this->type = type;
			this->num = num;
			this->pri = pri;
		}
		//GETTER
		string getType(){
			return this->type;
		};
		double getNum(){
			return this->num;
		}
		char getPri(){
			return this->pri;
		}
		//SETTER
		void setType(string type){
			this->type = type;
		}
		void setNum(double num){
			this->num = num;
		}
		void setPri(char pri){
			this->pri = pri;
		}
};

double solveRecursion(mathObject* arr, int leftIndex, int rightIndex){
	
	//Select the operation by least priority
	int minPriIndex = 0;
	int minPri = 99999;
	for(int z = leftIndex; z <= rightIndex; z++){
		int curPri = arr[z].getPri();
		if(curPri < minPri){
			minPri = curPri;
			minPriIndex = z;
		}

		if(arr[z].getType() == "bracket_open"){
			z = arr[z].getNum();
		}

	}

	Operations op;

	//Determining what to do for the operations
	string minPriType = arr[minPriIndex].getType();
	if(minPriType == "number"){
		return arr[minPriIndex].getNum();
	}else if(minPriType == "addition"){
		return (solveRecursion(arr, leftIndex, minPriIndex-1) + solveRecursion(arr, minPriIndex+1, rightIndex));
	}else if(minPriType == "substraction"){
		return (solveRecursion(arr, leftIndex, minPriIndex-1) - solveRecursion(arr, minPriIndex+1, rightIndex));
	}else if(minPriType == "division"){
		return (solveRecursion(arr, leftIndex, minPriIndex-1) / solveRecursion(arr, minPriIndex+1, rightIndex));
	}else if(minPriType == "multiplication"){
		return (solveRecursion(arr, leftIndex, minPriIndex-1) * solveRecursion(arr, minPriIndex+1, rightIndex));
	}else if(minPriType == "power"){
		return op.Exponent(solveRecursion(arr, leftIndex, minPriIndex-1), solveRecursion(arr, minPriIndex+1, rightIndex));
	}else if(minPriType == "sin"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * op.Sine(solveRecursion(arr, minPriIndex+1, rightIndex)));
		else
			return (op.Sine(solveRecursion(arr, minPriIndex+1, rightIndex)));
	}else if(minPriType == "cos"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * op.Cosine(solveRecursion(arr, minPriIndex+1, rightIndex)));
		else
			return (op.Cosine(solveRecursion(arr, minPriIndex+1, rightIndex)));
	}else if(minPriType == "tan"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * op.Tangent(solveRecursion(arr, minPriIndex+1, rightIndex)));
		else
			return (op.Tangent(solveRecursion(arr, minPriIndex+1, rightIndex)));
	}else if(minPriType == "log"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * op.Logarithm(solveRecursion(arr, minPriIndex+1, rightIndex)));
		else
			return (op.Logarithm(solveRecursion(arr, minPriIndex+1, rightIndex)));
	}else if(minPriType == "ln"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * op.NaturalLog(solveRecursion(arr, minPriIndex+1, rightIndex)));
		else
			return (op.NaturalLog(solveRecursion(arr, minPriIndex+1, rightIndex)));
	}else if(minPriType == "torad"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * op.ToRad(solveRecursion(arr, minPriIndex+1, rightIndex)));
		else
			return (op.ToRad(solveRecursion(arr, minPriIndex+1, rightIndex)));
	}else if(minPriType == "sqrt"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * op.SquareRoot(solveRecursion(arr, minPriIndex+1, rightIndex)));
		else
			return (op.SquareRoot(solveRecursion(arr, minPriIndex+1, rightIndex)));
	}else if(minPriType == "bracket_open"){
		if(leftIndex != minPriIndex)
			return (solveRecursion(arr, leftIndex, minPriIndex-1) * solveRecursion(arr, minPriIndex+1, rightIndex-1));
		else
			return solveRecursion(arr, leftIndex+1, rightIndex-1);
	}
}

double calculatorMachine(string input){
    //CLEAN INPUT (remove spaces and lowercase)
    for(int i = 0; i < input.length(); i++){
		if(input[i] == ' '){
			input.erase(i,1);
			i--;
		}
		input[i] = tolower(input[i]);
	}

//INITIALIZE mathObject ARRAY
	mathObject arr[input.length()];

//COVERTING string INPUT TO mathObject ARRAY

	// > BRACKET TELEPORT SYSTEM
	int bracketDepth = 0;
	int bracketTeleportHandler[20];

	// > INITIALIZE LOOP VARIABLES

	int i = 0, //INDEX being worked on
		t = 0; //target INDEX of mathObject arr

// > MAIN LOOP PARSING THE INPUT
    while(i < input.length()){
    	char cur = input[i];
    	if(cur == '('){
    		arr[t] = mathObject("bracket_open", 98);
    		bracketDepth++;
    		bracketTeleportHandler[bracketDepth] = t;
    		t++; i++;

		}else if(cur == ')'){
    		arr[t] = mathObject("bracket_close", -1);
    		arr[bracketTeleportHandler[bracketDepth]].setNum(t);
    		bracketDepth--;
    		t++; i++;

		}else if(cur == '^'){
			arr[t] = mathObject("power", 6);
    		t++; i++;

		}else if(cur == '*'){
			arr[t] = mathObject("multiplication", 4);
    		t++; i++;

		}else if(cur == '/'){
			arr[t] = mathObject("division", 3);
    		t++; i++;

		}else if(cur == '+'){
			arr[t] = mathObject("addition", 2);
    		t++; i++;

		}else if(cur == '-'){
			arr[t] = mathObject("substraction", 1);
    		t++; i++;

		}else if('0' <= cur && cur <= '9'){
			double frontTemp = 0; //infront of coma
			double backTemp = 0; //back of coma
			double behindComa = 0;
			while(true){

				if(input[i] == '.'){
					behindComa = 1;
				}else if(behindComa > 0){
					int toInt = input[i] - '0';
					backTemp = (backTemp*10) + toInt;
					behindComa++;
				}else{
					int toInt = input[i] - '0';
					frontTemp = (frontTemp*10) + toInt;
				}


				char nextInput = input[i+1];
				if((i+1) < input.length() && (('0' <= nextInput && nextInput <= '9') || nextInput == '.')){
					i++;
				}else{
					arr[t] = mathObject("number", 99, frontTemp+(backTemp/pow(10,behindComa-1)) );
					t++; i++;
					break;
				}
			}

		}else if('a' <= cur && cur <= 'z'){
			int startIn = i;
			while(true){
				char nextInput = input[i+1];
				if((i+1) < input.length() && ('a' <= nextInput && nextInput <= 'z')){
					i++;
				}else{
					string str = input.substr(startIn, i-startIn+1);
					if(str == "sin") arr[t] = mathObject("sin", 5);
					else if(str == "cos") arr[t] = mathObject("cos", 5);
					else if(str == "tan") arr[t] = mathObject("tan", 5);
					else if(str == "log") arr[t] = mathObject("log", 5);
					else if(str == "sqrt") arr[t] = mathObject("sqrt", 5);
					else if(str == "ln") arr[t] = mathObject("ln", 5);
					else if(str == "torad") arr[t] = mathObject("torad", 5);
					else{
						cout << "<!!!> ERROR: UNKNOWN FUNCTION" << endl;
						throw;
					}
					t++; i++;
					break;
				}
			}
		}else{
			cout << "<!!!> ERROR: UNRECOGNIZED INPUT" << endl;
			break;
		}
	}

	if(bracketDepth != 0){
		cout << "<!!!> ERROR: UNEVEN BRACKET" << endl;
		throw;
	}

	
	//INVOKE THE SOLVE RECURSION ON THE PARSED INPUT
	double toReturn = solveRecursion(arr, 0, t-1);
	return toReturn;
}
