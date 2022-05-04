#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


class Food {
public:
    Food();
    Food(string aName, int aProtein, int aCarbs, int aFat);
    ~Food();
    string getName() const;
    int getProtein() const;
    int getCarbs() const;
    int getFat() const;
    int getCalories() const;
    void setName(string aName);
    void setProtein(int aProtein);
    void setCarbs(int aCarbs);
    void setFat(int aFat);
    void printFood();
private:
    string mName;
    int mProtein;
    int mCarbs;
    int mFat;
    int mCalories = (mProtein * 4) + (mCarbs * 4) + (mFat * 9);

    void setCalories();
};