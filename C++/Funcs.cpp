#include "Funcs.h"

Food AddNewFood() {
    string name;
    cout << "Name:";
    cin >> name;
    cout << "Protein:";
    int protein = checkInputErrors();
    cout << "Carbs:";
    int carbs = checkInputErrors();
    cout << "Fat:";
    int fat = checkInputErrors();
    return {name, protein, carbs, fat};
}

string StringToLower(string input) {
    string newInput = input;
    transform(newInput.begin(), newInput.end(), newInput.begin(), ::tolower);
    return newInput;
}

int checkInputErrors() {
    int choice = 0;
    cin >> choice;
    while (!cin.good()) {
        cout << "\nInvalid input, try again...\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Try using number:";
        cin >> choice;
    }
    return choice;
}