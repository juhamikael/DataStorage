#include "Food.h"
#include "Funcs.h"

int main() {
    vector<Food *> foods;

    // Adding placeholder data////////
    cout << "-----------------------\nAdding placeholder data to vector\n";
    foods.push_back(new Food("Jauheliha", 20, 0, 10));
    foods.push_back(new Food("Kana", 18, 0, 0));
    foods.push_back(new Food("Kala", 20, 0, 20));
    foods.push_back(new Food("Suklaa", 11, 49, 33));
    cout << foods.size() << " foods added \n-----------------------\n\n\n";
    // ////////

    // Global Variables
    string nameToRemove;
    string nameToSearch;
    bool foodFound = false;
    int choice;
    int setChangeFoodChoice;
    string newFoodName;
    int newValue;


    cout << "Welcome to the food database!\n";
    do {
        cout << "-----------------------\n"
                "1. Add new food\n"
                "2. Remove food\n"
                "3. Print all foods\n"
                "4. Search for food\n"
                "5. Sort foods by calories\n"
                "6. Change details of food\n"
                "7. Exit\n";
        cout << "Enter your choice:";
        choice = checkInputErrors();

        switch (choice) {
            case 1:
                foods.push_back(new Food(AddNewFood()));
                break;
            case 2:
                cout << "Enter food name to remove: ";
                cin >> nameToRemove;
                for (Food *i: foods) {
                    if (i->getName() == nameToRemove) {
                        foods.erase(find(foods.begin(), foods.end(), i));
                        foodFound = true;
                        break;
                    }
                }
                if (!foodFound) {
                    foodFound = false;
                    cout << "Food not found!\n";
                }
                break;
            case 3:
                cout << "\n\n-------\nFoods found: " << foods.size() << "\n-------";
                for (auto &&food: foods) {
                    food->printFood();
                }
                break;
            case 4:
                cout << "Enter food name to search: ";
                cin >> nameToSearch;
                nameToSearch = StringToLower(nameToSearch);
                // Iterate through vector and get index if found
                for (Food *i: foods) {
                    if (StringToLower(i->getName()) == nameToSearch) {
                        foodFound = true;
                        cout << "Food with name '" << i->getName() << "' found!\n";
                        i->printFood();
                        break;
                    }
                }
                if (!foodFound) {
                    foodFound = false;

                    cout << "\nFood with name '" << nameToSearch << "' not found! :(\n\n";
                    break;
                }
            case 5:
                sort(foods.begin(), foods.end(), [](Food *a, Food *b) {
                    return a->getCalories() < b->getCalories();
                });
                break;
            case 6:
                cout << "Enter food name search: ";
                cin >> nameToSearch;
                nameToSearch = StringToLower(nameToSearch);
                for (int i = 0; i < foods.size(); i++) {
                    if (StringToLower(foods[i]->getName()) == nameToSearch) {
                        cout << "\nFood with name '" << foods[i]->getName() << "' found!\n";
                        foodFound = true;
                        do {
                            cout << "\n1. Change food name\n"
                                    "2. Change food protein value\n"
                                    "3. Change food carb value\n"
                                    "4. Change food fat value\n"
                                    "5. Print food values\n"
                                    "6. Go back to main menu\n";
                            setChangeFoodChoice = checkInputErrors();
                            switch (setChangeFoodChoice) {
                                case 1:
                                    cout << "Give new name:\n";
                                    cin >> newFoodName;
                                    foods[i]->setName(newFoodName);
                                    break;
                                case 2:
                                    cout << "Give new Protein value:\n";
                                    cin >> newValue;
                                    foods[i]->setProtein(newValue);
                                    break;
                                case 3:
                                    cout << "Give new Carb value:\n";
                                    cin >> newValue;
                                    foods[i]->setCarbs(newValue);
                                    break;
                                case 4:
                                    cout << "Give new Fat value:\n";
                                    cin >> newValue;
                                    foods[i]->setFat(newValue);
                                    break;
                                case 5:
                                    foods[i]->printFood();
                                    break;
                                case 6:
                                    cout << "Going back go main menu...\n";
                                    break;
                            }
                        } while (setChangeFoodChoice != 6);
                    }
                }
                if (!foodFound) {
                    cout << "\nFood with name '" << nameToSearch << "' not found! :(\n\n";
                }
                foodFound = false;
                break;
            case 7:
                cout << "Exiting...\n";
                for (auto &food: foods) {
                    delete food;
                }
                break;
            default:
                cout << "Invalid input, try again..." << endl;
        }
    } while (choice != 7);
}

