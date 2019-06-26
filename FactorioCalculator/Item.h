#pragma once
#include "Graph.h"
#include "Simple_window.h" 
#include <iostream>
#include <string>
#include <fstream>
#include "std_lib_facilities.h"
#include "fileReading.h"
using namespace std;

class Item
{

	//what i want here is a list of what items are requered to create this item, and how many
	//also i want how much time and energy if applicable
	//maybe have every item have category and such, but leave as a default value if not applicable

	int createdAmount = 1;
	int energy;
	
	vector<Item*> ingredients;

	vector<string> names;

	vector<int> numberOfIngredients;

public:
	Item(string name, int amount, int energy, vector<int> numberOfIngredients, vector<string> names);
	//~Item();
};

