#include "FoodSingleton.h"

FoodSingleton *FoodSingleton::instance = nullptr;

int FoodSingleton::getFoods() {
    return foodsInVector;
}

FoodSingleton *FoodSingleton::getInstance() {
    if (instance == nullptr) {
        instance = new FoodSingleton();
    }
    return instance;
}

void FoodSingleton::updateFoods(int vectorSize) {
    foodsInVector = vectorSize;
}

FoodSingleton::FoodSingleton() {
    foodsInVector = 0;
}



