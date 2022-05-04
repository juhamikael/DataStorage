#include "Funcs.h"

Food AddNewFood() {
// This function supposed to be function to add hide couts and cins when adding new food to the list
// But this is calling destructor of Food class, so ignoring this for now
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
    int value = 0;
    cin >> value;
    while (!cin.good()) {
        cout << "\nInvalid input, try again...\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Try using number:";
        cin >> value;
    }
    return value;
}

void printChoiceMenu(int menu) {
    if (menu == 1) {
        cout << "-----------------------\n"
                "1. Add new food\n"
                "2. Remove food\n"
                "3. Print all foods\n"
                "4. Search for food\n"
                "5. Sort foods by calories\n"
                "6. Change details of food\n"
                "7. Exit\n";
        cout << "Enter your choice:";
    } else if (menu == 2) {
        cout << "\n1. Change food name\n"
                "2. Change food protein value\n"
                "3. Change food carb value\n"
                "4. Change food fat value\n"
                "5. Print food values\n"
                "6. Go back to main menu\n";
    }
}

void foodFoundNotification(bool found, const string &name) {
    if (found) {
        cout << "Food with name '" << name << "' found!\n";
    } else {
        cout << "\nFood with name '" << name << "' not found! :(\n\n";
    }
}