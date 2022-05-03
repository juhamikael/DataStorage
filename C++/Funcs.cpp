#include "Funcs.h"
Foods AddNewFood() {
    string name;
    int protein;
    int carbs;
    int fat;
    cout << "Name:";
    cin >> name;
    cout << "Protein:";
    cin >> protein;
    cout << "Carbs:";
    cin >> carbs;
    cout << "Fat:";
    cin >> fat;
    return {name, protein, carbs, fat};
}

string StringToLower(string input) {
    string newInput = input;
    transform(newInput.begin(), newInput.end(), newInput.begin(), ::tolower);
    return newInput;
}

int checkInputErrors() {
    int choice = 0;
    cout << "Enter your choice:";
    cin >> choice;
    while (!cin.good()) {
        cout << "\nInvalid input, try again...\n\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter your choice:\n";
        cin >> choice;
    }
    return choice;
}