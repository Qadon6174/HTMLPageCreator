#include "inputCommands.h"
#include "page.h"
#include <fstream>

int main() {
	enum states { title, create, load, onPage, save };
	states currentState = title;
	page newPage;
	string input;
	string fileName;
	ifstream inFile;
	string currentClass;
	ofstream outFile;
	int tries = 1;
	int currentPosition = 0;

	while (1) {
		switch (currentState) {
		case(title):
			cout << "Welcome to Quinn Donahue's C++ HTML Website Development Software." << endl;
			cout << "Please input the title of your file to begin, or type \"exit\" to exit." << endl;
			cin >> input;
			if (input == "exit") {
				exit(-1);
			}
			currentState = create;
			break;
		case(create):
			currentPosition = 0;
			newPage = page();
			tries = 1;
			inFile.open(input + ".html");
			if (inFile.is_open()) {
				std::cout << "Opening File" << endl;
				currentState = onPage;
				newPage = scanHTML(input+".html");
				for (string x : newPage.getTags()) {
					currentPosition++;
				}
				
				inFile.close();
				break;
			}
			if (tries == 1) {
				fileName = input + ".html";
			}
			else {
				fileName = input + to_string(tries) + ".html";
			}
			newPage.setFileName(fileName);
			currentState = onPage;
			break;
		case(onPage):
			cout << "Please input a tag to add or issue a command" << endl;
			cin >> input;
			if (input == "print") {
				cout << "File: " << newPage.getFileName() << endl;
				cout << newPage;
			}
			else if (input == "p") {
				if (currentClass == "") {
					newPage.addTag(para(), currentPosition);
					currentPosition++;
				}
				else {
					newPage.addTag(para(currentClass), currentPosition);
					currentPosition++;
				}
			}
			else if (input == "h") {
				if (currentClass == "") {
					newPage.addTag(header(), currentPosition);
					currentPosition++;
				}
				else {
					newPage.addTag(header(currentClass),currentPosition);
					currentPosition++;
				}
			}
			else if (input == "insert") {
				while (1) {
					int counter = 0;
					for (string s : newPage.getTags()) {
						cout << counter << " - " << s << endl;
						counter++;
					}
					std::cout << "Enter a position number" << endl;
					cin >> input;
					try {
						currentPosition = stoi(input);
					}
					catch (...) {
						cout << "Input is not an integer" << endl;
						continue;
					}
					if (currentPosition < 0 || currentPosition > newPage.getTags().size() - 1) {
						std::cout << "Invalid Position";
						continue;
					}
					break;
				}
			}
			else if (input == "remove") {
				cout << "Which tag would you like to remove?" << endl;
				int counter = 0;
				for (string s : newPage.getTags()) {
					cout << counter << " - " << s << endl;
					counter++;
				}
				while (1) {
					cin >> input;
					try {
						newPage.remTag(stoi(input));
					}
					catch (...) {
						cout << "Input is not an integer" << endl;
						continue;
					}
					if (currentPosition >= stoi(input)) {
						currentPosition--;
					}
					break;
				}
			}
			else if (input == "end") {
				currentPosition = newPage.getTags().size() - 1;
			}
			else if (input == "custom") {
				std::cout << "Give Custom Text" << endl;
				cin.ignore(1i64, '\n');
				getline(cin, input);
				newPage.addTag(input, currentPosition);
				currentPosition++;
			}
			else if (input == "save") {
				outFile.open(newPage.getFileName());
				outFile << newPage;
				cout << "Page Saved" << endl;

			}
			else if (input == "exit") {
				newPage.clearPage();
				currentState = title;
				break;
			}
			else if (input == "setCSS") {
				cout << "Please type in CSS file (minus .css)" << endl;
				cin >> input;
				newPage.setCssFile(input+".css");
			}
			else if (input == "help") {
				cout << "p        - add a paragraph tag" << endl;
				cout << "h        - add a header tag" << endl;
				cout << "insert   - change where the cursor is" << endl;
				cout << "end      - set the cursor to the end of the page" << endl;
				cout << "save     - save the page" << endl;
				cout << "exit     - exit this menu" << endl;
				cout << "setCSS   - set the CSS file" << endl;
				cout << "help     - print help commands" << endl;
			}
			else if (input == "setClass") {
				cout << "Input class change (or type \"clear\" to clear)" << endl;
				cin >> currentClass;
				if (currentClass == "clear") {
					currentClass = "";

				}
				break;
			}
			else {
				cout << "Input not registered" << endl;
			}
			break;
		}
	}
}