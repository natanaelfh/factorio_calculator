// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
#include <iostream>
#include <string>
#include <fstream>
#include "std_lib_facilities.h"
#include "fileReading.h"
#include "item.h"
using namespace std;


int main() {
	//char c;
	//string line;
	//ifstream myfile("recipe.lua");
	//if (myfile.is_open()) {
	//	/*while (myfile.get(c)) {
	//		cout << c;
	//	}
	//	myfile.close();*/

	//	myfile.seekg(0, myfile.end);
	//	int length = myfile.tellg();
	//	myfile.seekg(0, myfile.beg);

	//	string contents(length + 1, '\0');


	//	myfile.read(&contents[0], length);
	//	cout << contents;
	//}
	//else cout << "unable dkkdkd";

	string contents = readFile();

	unwrap(contents, '{', '}');

	vector<string> list = separate(contents, '{', '}');

	
	createItems(list[0]);
	

}