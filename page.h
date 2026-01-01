#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class page {
private:
	string fileName;
	string cssFile;
	vector <string> tags;
	string pageName;
public:
	page();
	void setFileName(string);
	string getFileName();
	void setCssFile(string);
	string getCssFile();
	void addTag(string);
	void addTag(string, int);
	void remTag(int);
	vector <string> getTags();
	void setPageName(string);
	string getPageName();
	friend ostream& operator << (ostream&, const page&);
	void clearPage();
};