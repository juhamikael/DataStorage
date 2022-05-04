#include "Food.h"
#include "Funcs.h"
#include "FoodSingleton.h"

int main() {
    vector<shared_ptr<Food>> foods;
    FoodSingleton *singleton = FoodSingleton::getInstance();
    // ////////////////////////////////
    // Global Variables
    string nameToRemove;
    string nameToSearch;
    bool foodFoundStatus = false;
    int choice;
    int setChangeFoodChoice;
    string newFoodName;
    int newValue;
    string name;
    int protein;
    int fat;
    int carbs;


    // ////////////////////////////////

    // Adding placeholder data/////////
    // ////////////////////////////////
    cout << "-----------------------\nAdding placeholder data to vector\n";
    foods.push_back(make_shared<Food>("Jauheliha", 20, 0, 10));
    foods.push_back(make_shared<Food>("Kana", 18, 0, 0));
    foods.push_back(make_shared<Food>("Kala", 20, 0, 20));
    foods.push_back(make_shared<Food>("Suklaa", 11, 49, 33));
    singleton->updateFoods(foods.size());
    cout << singleton->getFoods() << " foods added \n-----------------------\n\n\n";
    // ////////////////////////////////


    // ////////////////////////////////
    // Start of program
    cout << "Welcome to the food database!\n";
    do {
        printChoiceMenu(1);
        choice = checkInputErrors();
        switch (choice) {
            case 1:
                cout << "Name:";
                cin >> name;
                cout << "Protein:";
                protein = checkInputErrors();
                cout << "Carbs:";
                carbs = checkInputErrors();
                cout << "Fat:";
                fat = checkInputErrors();
                foods.push_back(make_shared<Food>(name, protein, carbs, fat));
                singleton->updateFoods(foods.size());
                break;
            case 2:
                cout << "Enter food name to remove: ";
                cin >> nameToRemove;
                // Ignore case sensitivity and change name & nameToRemove to lowercase
                nameToRemove = StringToLower(nameToRemove);
                for (auto &i: foods) {
                    if (StringToLower(i->getName())== nameToRemove) {
                        foodFoundStatus = true;
                        foodFoundNotification(foodFoundStatus, nameToRemove);
                        foods.erase(find(foods.begin(), foods.end(), i));
                        break;
                    }
                }
                // Changing foodFoundStatus to false before breaking case 2
                singleton->updateFoods(foods.size());
                foodFoundStatus = false;
                break;
            case 3:
                cout << "\n\n-------\nFoods found: " << singleton->getFoods() << "\n-------";
                for (auto &&food: foods) {
                    food->printFood();
                }
                if (singleton->getFoods() == 0) {
                    foods.clear();
                    cout << "\nFOOD-LIST IS EMPTY\n";
                    break;
                }
                break;
            case 4:
                cout << "Enter food name to search: ";
                cin >> nameToSearch;
                nameToSearch = StringToLower(nameToSearch);
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
                sort(foods.begin(), foods.end(), [](const shared_ptr<Food> &a, const shared_ptr<Food> &b) {
                    return a->getCalories() < b->getCalories();
                });
                cout << "\n Foods sorted\n";
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
                                    newValue = checkInputErrors();
                                    i->setProtein(newValue);
                                    break;
                                case 3:
                                    cout << "Give new Carb value:\n";
                                    newValue = checkInputErrors();
                                    i->setCarbs(newValue);
                                    break;
                                case 4:
                                    cout << "Give new Fat value:\n";
                                    newValue = checkInputErrors();
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

