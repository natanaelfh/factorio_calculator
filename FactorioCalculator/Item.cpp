#include "Item.h"


Item::Item(string name, int amount, int energy, vector<int> numberOfIngredients, vector<string> names)
{
	this->createdAmount = amount;
	this->energy = energy;
	this->names = names;
	this->numberOfIngredients = numberOfIngredients;

}

