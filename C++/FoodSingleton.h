
#pragma once

class FoodSingleton {
public:

    static FoodSingleton *getInstance();
    int getFoods();
    void updateFoods(int vectorSize);

private:
    FoodSingleton();
    int foodsInVector = 0;
    static FoodSingleton *instance;
};
