#include "fileReading.h"

void unwrap(string & str, const char startchar, const char endchar)
{
	//will delete all characters outside the first set of curly brackets
	//NB if the string is like this {sdfasdf}{asdfasd} it will remove both set of curly brackets
	int numOfBrackets{ 0 };
	bool del;


	for (string::iterator it = str.begin(); it != str.end();) {
		if (numOfBrackets == 0) {
			del = true;
		}
		else {
			del = false;
		}
		if (*it == startchar) {
			numOfBrackets += 1;
		}
		else if (*it == endchar) {

			numOfBrackets -= 1;
		}

		if (del) {
			str.erase(it);
		}
		else {
			it++;
		}
	}

}


vector<string> separate(string & str, const char startchar, const char endchar) {
	// i want this to separate the list of recipes into an array of strings
	//maybe use something like a vector<string> and also have a temp string to store everything you woudnt delete from the fuction above and put it in an elemet
	//it wil go from numOfBrackets 1 -> 0, that means you are now outside the last curlybracket and can push the last buffer string into the array and start a new buffer string

	vector<string> listOfStrings;
	string buffer;
	int numOfBrackets{ 0 };

	for (string::iterator it = str.begin(); it != str.end();it++) {

		if (*it == endchar) {
			numOfBrackets -= 1;
		}
		if (numOfBrackets == 0) {
			if (buffer.size() > 0) {
				listOfStrings.push_back(buffer);
				buffer = "";
			}
		}
		else {
			buffer.push_back(*it);
		}

		if (*it == startchar) {
			numOfBrackets += 1;
		}
	}

	return listOfStrings;

}

vector<vector<string>> getEverySetting(string input)
{
	//I want to return a list of two strings
	//one with the name of the setting and one with the value of the setting


	//something like everytime there is a comma add it to the string
	//and also at the end. then remove the equals sign and the two spaces
	int num{ 0 };
	string tempString;
	vector<string> tempStrings;
	for (char c : input) {
		if (c == ',' && num == 0) {
			tempStrings.push_back(tempString);
			tempString = "";
		}
		else {
			tempString.push_back(c);
		}

		if (c == '{') {
			num += 1;
		}
		if (c == '}') {
			num -= 1;
		}
	}
	tempStrings.push_back(tempString);

	vector<string> names;
	vector<string> values;

	unsigned place;
	for (string s : tempStrings) {
		place = s.find('=');
		names.push_back(s.substr(0, place - 1));
		values.push_back(s.substr(place + 1, -1));
		}


	vector<vector<string>> result{};
	result.push_back(names);
	result.push_back(values);

	return result;
}

string readFile() {
	string error{ "It didnt read \n" };
	string inputFileName;
	cout << "What is the file name? \n";
	cin >> inputFileName;

	ifstream file(inputFileName);
	if (file.is_open()) {
		file.seekg(0, file.end);
		int length = file.tellg();
		file.seekg(0, file.beg);
		string contents(length + 1, '\0');
		file.read(&contents[0], length);

		file.close();
		return contents;
	}
	else {
		return error;
	}
}

void createItems(string input) {
	vector<vector<string>> settings;
	settings = getEverySetting(input);
	vector<std::string> names = settings[0];
	vector<std::string> values = settings[1];
	std::string sss{ "type" };
	vector<std::string>::iterator it = find(names.begin(), names.end(), sss);

	std::string type;

	if (it != names.end()) {
		type = *it;
	}
	cout << type;
}