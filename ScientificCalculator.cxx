#include "ScientificCalculator.hxx"

using namespace std;

ScientificCalculator::ScientificCalculator() {
    // Initialize the saved value to 0.
    this->currentlySavedValue = 0;
    getExpressionFromUser();
}

bool ScientificCalculator::getExpressionFromUser(){
    // Check if userLogs is empty, if not, print the currently saved value.
    if (!this->userLogs.empty()) cout << "Current value: " << this->currentlySavedValue;
    // Ask the user for a mathematical expression to parse.
    cout << "Enter expression here: ";
    // Assign the value into userInput.
    cin >> this->userInput;
    // Clear and flush the stdin stream. 
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Call validateExpression() and return its value.
    return this->validateExpression();
}

void ScientificCalculator::clearLogs(){
    // Check if the list is empty. If not, clear the list for reuse.
    if (this->userLogs.empty()) return;
    this->userLogs.clear();
}

ScientificCalculator::~ScientificCalculator(){
    // Call clearLogs() to delete all user logs along with the calculator.
    this->clearLogs();
}

void ScientificCalculator::printLogs(){
    // Check if the list is empty. If yes, print out a different message and return early.
    cout << "Logs: " << '\n';
    if (this->userLogs.empty()) {
        cout << "Empty." << endl;
        return;
    }

    // Initialize variable to store log indices.
    size_t logIndex = 1;

    // Iterate over the list and print out every expression and its associated value.
    for (list<Logs>::iterator listIterator = this->userLogs.begin(); listIterator != this->userLogs.end(); listIterator++){
        cout << "\n\t" << logIndex << ":\t\"" << (*listIterator).pastExpressions << "\", Value: " << (*listIterator).expressionResult << '\n';
        // Increment the log index.
        logIndex++;
    }
}