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
	
	//SELECT THE OPERATION BY LEAST PRIORITY
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
