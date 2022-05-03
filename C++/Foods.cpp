#include "Foods.h"


Foods::Foods() : mName("None"), mProtein(0), mCarbs(0), mFat(0) {
    cout << "Foods default constructor called\n";
}

Foods::Foods(string aName, int aProtein, int aCarbs, int aFat)
        : mName(aName), mProtein(aProtein), mCarbs(aCarbs), mFat(aFat) {
    cout << "Foods 4 parameter constructor called with name: '" << mName << "'\n";
}

Foods::~Foods() {
    cout << "Foods destructor called and food with name: '" << mName << "' deleted\n";
}

string Foods::getName() const {
    return mName;
}

int Foods::getProtein() const {
    return mProtein;
}

int Foods::getCarbs() const {
    return mCarbs;
}

int Foods::getFat() const {
    return mFat;
}

int Foods::getCalories() const {
    return mCalories;
}

void Foods::setName(string aName) {
    this->mName = aName;
}

void Foods::setProtein(int aProtein) {
    this->mProtein = aProtein;
    this->setCalories();
}

void Foods::setCarbs(int aCarbs) {
    this->mCarbs = aCarbs;
    this->setCalories();
}

void Foods::setFat(int aFat) {
    this->mFat = aFat;
    this->setCalories();
}
void Foods::setCalories(){
    this->mCalories = (mProtein * 4) + (mCarbs * 4) + (mFat * 9);
}

void Foods::printFood() {
    cout << "\n-------\n";
    cout << "Name: " << getName() << endl;
    cout << "Protein: " << getProtein() << endl;
    cout << "Carbs: " << getCarbs() << endl;
    cout << "Fat: " << getFat() << endl;
    cout << "Calories: " << getCalories() << endl;
    cout << "-------\n";

}


