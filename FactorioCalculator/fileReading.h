#pragma once
#include "Graph.h"
#include "Simple_window.h" 
#include <iostream>
#include <string>
#include <fstream>
#include "std_lib_facilities.h"
#include "Item.h"
#include <vector>

using namespace std;

//I want something to take a string and remove everything between two curlybrackets
//so I can use it on recipe.lua multiple times untill i have a list off only the recipies
//Maybe use refrences so that i dont need to keep everything in memory

void unwrap(string & str, const char startchar, const char endchar);

string readFile();

vector<string> separate(string & str, const char startchar, const char endchar);

void createItems(string input);

vector<vector<string>> getEverySetting(string input);