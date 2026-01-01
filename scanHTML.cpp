#include "inputCommands.h"
page scanHTML(string fileName) {
	string line;
	string temp;
	page newPage;
	ifstream inFile;
	inFile.open(fileName);
	newPage.setFileName(fileName);
	bool isBody = false;
	while (getline(inFile, line)) {
		if (line == "<body>") {
			isBody = true;
			continue;
		}
		if(!isBody){
			if (line.substr(0, 7) == "<title>") {
				string temp = line.substr(6, line.size() - 15);
				cout << "Title: " << temp << endl;
				newPage.setPageName(temp);
				continue;
			}
			if (line.substr(0, 23) == "<link rel=\"stylesheet\"") {
				temp = line.substr(32, line.size() - 33);
				cout << "Style Sheet: " << temp << endl;
				continue;
			}
			continue;
		}
		if (line == "</body>") {
			break;
		}
		newPage.addTag(line);
	}
	return(newPage);
}