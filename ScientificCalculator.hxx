#ifndef SCICALC
#define SCICALC

#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

/// @brief Object for storing user logs.
struct Logs {
    /// @brief String containing past expression.
    string pastExpressions;
    /// @brief Value of the associated expression.
    double expressionResult;
};

/// @brief Scientific calculator object.
class ScientificCalculator {
    private:
        /// @brief Value of currently saved history.
        double currentlySavedValue;
        /// @brief Mathematical expression to be evaluated.
        string userInput;
        /// @brief list storing all saved user logs.
        list<Logs> userLogs; 
        /// @brief Private method for calculating sin(angle).
        /// @param angle Angle to be computed.
        /// @return sin(angle).
        double sine(double angle);
        /// @brief Private method for calculating cos(angle).
        /// @param angle Angle to be computed.
        /// @return cos(angle).
        double cosine(double angle);
        /// @brief Private method for calculating tan(angle).
        /// @param angle Angle to be computed.
        /// @return tan(angle) if cos(angle) is not 0, NaN otherwise.
        double tangent(double angle);
        /// @brief Private method for calculating exp(power);
        /// @param power Power to raise the number by.
        /// @param baseNumber Value of the base number.
        /// @return exp(power, baseNumber).
        double exponent(double power, double baseNumber);
        /// @brief Private method for calculating ln(number).
        /// @param number Value given to the function.
        /// @return ln(number) if number > 0, NaN otherwise. 
        double naturalLogarithm(double number);
        /// @brief Private method for calculating log10(number)
        /// @param number Value given to the function
        /// @return log10(number) if number > 0, NaN otherwise.
        double base10Logarithm(double number);
        /// @brief Private method for calculating the product between two numbers.
        /// @param firstNumber First number.
        /// @param secondNumber Second number.
        /// @return The product between firstNumber and secondNumber.
        double product(double firstNumber, double secondNumber);
        /// @brief Private method for calculating the sum of two numbers.
        /// @param firstNumber First number.
        /// @param secondNumber Second number.
        /// @return The sum between firstNumber and secondNumber. 
        double sum(double firstNumber, double secondNumber);
        /// @brief Private method for calculating the difference between two numbers.
        /// @param firstNumber First number.
        /// @param secondNumber Second number.
        /// @return The difference between firstNumber and secondNumber.
        double difference(double firstNumber, double secondNumber);
        /// @brief Private method for calculating the division of two numbers.
        /// @param numerator Number to be divided.
        /// @param denominator Divisor. 
        /// @return numerator/denominator if denominator != 0, NaN otherwise.
        double division(double numerator, double denominator);
        /// @brief Private method for calculating the square root of a number
        /// @param number Value given to the function.
        /// @return sqrt(number) if number > 0, NaN otherwise.
        double squareRoot(double number);
        /// @brief Private method for evaluating a parsed mathematical expression.
        /// @param expression Expression to evaluate.
        /// @return Result of the parsed equation if the equation is valid. NaN otherwise. 
        double evaluateExpression(vector<string> expression);
        /// @brief Private method for validating a given user expression.
        /// @return True if the expression is valid. False otherwise.
        bool validateExpression();
    public:
        /// @brief Default constructor for the object.
        ScientificCalculator();
        /// @brief Method for getting mathematical expression from user.
        /// @returns True if user input is valid, false otherwise. 
        bool getExpressionFromUser();
        /// @brief Method for processing user expression.
        /// @returns true if the evaluation succedds, false otherwise.
        bool processExpression();
        /// @brief Method for undoing most recent evaluated expression.
        /// @return true if the undo is successful, false otherwise.
        bool undoCalculation();
        /// @brief Method for clearing all user logs.
        void clearLogs();
        /// @brief Method for printing all user logs.
        void printLogs();
        /// @brief Default destructor for the object.
        ~ScientificCalculator();
};
  
#endif