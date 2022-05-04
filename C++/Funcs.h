#include "Food.h"
#include <algorithm>
#pragma once

// Constructor
Food AddNewFood();
string StringToLower(string input);
int checkInputErrors();
void printChoiceMenu(int menu);
void foodFoundNotification(bool found, const string& name);
