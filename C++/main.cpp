#include "Food.h"
#include "Funcs.h"

int main() {
    vector<unique_ptr<Food>> foods;

    // Adding placeholder data/////////
    // ////////////////////////////////
    cout << "-----------------------\nAdding placeholder data to vector\n";
    foods.push_back(make_unique<Food>("Jauheliha", 20, 0, 10));
    foods.push_back(make_unique<Food>("Kana", 18, 0, 0));
    foods.push_back(make_unique<Food>("Kala", 20, 0, 20));
    foods.push_back(make_unique<Food>("Suklaa", 11, 49, 33));
    cout << foods.size() << " foods added \n-----------------------\n\n\n";
    // ////////////////////////////////

    // ////////////////////////////////
    // Global Variables
    string nameToRemove;
    string nameToSearch;
    bool foodFound = false;
    int choice;
    int setChangeFoodChoice;
    string newFoodName;
    int newValue;
    // ////////////////////////////////

    // ////////////////////////////////
    // Start of program
    cout << "Welcome to the food database!\n";
    do {
        printChoiceMenu(1);
        choice = checkInputErrors();
        switch (choice) {
            case 1:
                foods.push_back(make_unique<Food>(AddNewFood()));
                break;
            case 2:
                cout << "Enter food name to remove: ";
                cin >> nameToRemove;
                for (auto &i: foods) {
                    if (StringToLower(i->getName())== nameToRemove) {
                        foodFoundStatus = true;
                        foodFoundNotification(foodFoundStatus, nameToRemove);
                        foods.erase(find(foods.begin(), foods.end(), i));
                        foodFound = true;
                        break;
                    }
                }
                foodNotFound(foodFound, nameToRemove);
                foodFound = false;
                break;
            case 3:
                cout << "\n\n-------\nFood found: " << foods.size() << "\n-------";
                for (auto &&food: foods) {
                    food->printFood();
                }
                break;
            case 4:
                cout << "Enter food name to search: ";
                cin >> nameToSearch;
                nameToSearch = StringToLower(nameToSearch);
                // Iterate through vector and get index if found
                for (auto &i: foods) {
                    if (StringToLower(i->getName()) == nameToSearch) {
                        foodFoundStatus = true;
                        foodFoundNotification(foodFoundStatus, nameToSearch);
                        i->printFood();
                        break;
                    }
                }
                foodFoundNotification(foodFoundStatus, nameToSearch);
                foodFoundStatus = false;
                break;
            case 5:
                sort(foods.begin(), foods.end(), [](const unique_ptr<Food> &a, const unique_ptr<Food> &b) {
                    return a->getCalories() < b->getCalories();
                });
                break;
            case 6:
                cout << "Enter food name search: ";
                cin >> nameToSearch;
                nameToSearch = StringToLower(nameToSearch);
                for (auto &i: foods) {
                    if (StringToLower(i->getName()) == nameToSearch) {
                        foodFoundStatus = true;
                        foodFoundNotification(foodFoundStatus, nameToSearch);
                        do {
                            printChoiceMenu(2);
                            setChangeFoodChoice = checkInputErrors();
                            switch (setChangeFoodChoice) {
                                case 1:
                                    cout << "Give new name:\n";
                                    cin >> newFoodName;
                                    i->setName(newFoodName);
                                    break;
                                case 2:
                                    cout << "Give new Protein value:\n";
                                    cin >> newValue;
                                    i->setProtein(newValue);
                                    break;
                                case 3:
                                    cout << "Give new Carb value:\n";
                                    cin >> newValue;
                                    i->setCarbs(newValue);
                                    break;
                                case 4:
                                    cout << "Give new Fat value:\n";
                                    cin >> newValue;
                                    i->setFat(newValue);
                                    break;
                                case 5:
                                    i->printFood();
                                    break;
                                case 6:
                                    cout << "Going back go main menu...\n";
                                    break;
                            }
                        } while (setChangeFoodChoice != 6);
                    }
                }
                foodFoundNotification(foodFoundStatus, nameToRemove);
                foodFoundStatus = false;
                break;
            case 7:
                foods.clear();
                cout << "Food list cleared!\n\n";
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input, try again..." << endl;
        }
    } while (choice != 7);
}

