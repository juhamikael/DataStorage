//
// Created by Juha on 02/05/2022.
//

#include "Food.h"


Food::Food() : mName("None"), mProtein(0), mCarbs(0), mFat(0) {
    cout << "Food default constructor called\n";
}

Food::Food(string aName, int aProtein, int aCarbs, int aFat)
        : mName(aName), mProtein(aProtein), mCarbs(aCarbs), mFat(aFat) {
    cout << "Food 4 parameter constructor called with name: '" << mName << "'\n";
}

Food::~Food() {
    cout << "Food destructor called and food with name: '" << mName << "' deleted\n";
}

string Food::getName() const {
    return mName;
}

int Food::getProtein() const {
    return mProtein;
}

int Food::getCarbs() const {
    return mCarbs;
}

int Food::getFat() const {
    return mFat;
}

int Food::getCalories() const {
    return mCalories;
}

void Food::setName(string aName) {
    this->mName = aName;
}

void Food::setProtein(int aProtein) {
    this->mProtein = aProtein;
    this->setCalories();
}

void Food::setCarbs(int aCarbs) {
    this->mCarbs = aCarbs;
    this->setCalories();
}

void Food::setFat(int aFat) {
    this->mFat = aFat;
    this->setCalories();
}
void Food::setCalories(){
    this->mCalories = (mProtein * 4) + (mCarbs * 4) + (mFat * 9);
}

void Food::printFood() {
    cout << "\n-------\n";
    cout << "Name: " << getName() << endl;
    cout << "Protein: " << getProtein() << endl;
    cout << "Carbs: " << getCarbs() << endl;
    cout << "Fat: " << getFat() << endl;
    cout << "Calories: " << getCalories() << endl;
    cout << "-------\n";

}


