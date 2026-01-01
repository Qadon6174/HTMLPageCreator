//Various functions for deciding tags
#include "inputCommands.h"

string header() {
	string input1;
	bool flag = false;
	int headerSize;
	string headerContents;
	while(true){
		cout << "Input header size" << endl;
		cin >> input1;
		try {
			headerSize = stoi(input1);
		}
		catch (...){
			cout << "Input is not an integer" << endl;
			continue;
		}
		if (headerSize < 5) {
			break;
			
		}
		cout << "Header Size not in configuration" << endl;
	}
	cout << "Input header contents (press enter when done)." << endl;
	cin.ignore(1i64, '\n');
	getline(cin, headerContents);
	string output = "<h" + input1 + ">" + headerContents + "</h" + input1 + ">";
	return(output);
}
string header(string type) {
	string input1;
	bool flag = false;
	int headerSize;
	string headerContents;
	while (true) {
		cout << "Input header size" << endl;
		cin >> input1;
		try {
			headerSize = stoi(input1);
		}
		catch (...) {
			cout << "Input is not an integer" << endl;
			continue;
		}
		if (headerSize < 5) {
			break;

		}
		cout << "Header Size not in configuration" << endl;
	}
	cout << "Input header contents (press enter when done)." << endl;
	cin.ignore(1i64, '\n');
	getline(cin, headerContents);
	string output = "<h" + input1 + " class = \""+type+"\">" + headerContents + "< / h" + input1 + ">";
	return(output);
}
string para() {
	string paraContents;
	cout << "Input paragraph contents (press enter when done)." << endl;
	cin.ignore(1i64, '\n');
	getline(cin, paraContents);
	string output = "<p>" + paraContents + "</p>";
	return(output);
}
string para(string type) {
	string paraContents;
	cout << "Input paragraph contents (press enter when done)." << endl;
	cin.ignore(1i64, '\n');
	getline(cin, paraContents);
	string output = "<p class = \"" + type + "\">" + paraContents + "</p>";
	return(output);
}