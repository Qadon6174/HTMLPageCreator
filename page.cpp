#include "page.h"
page::page():
	fileName(""),cssFile(""),pageName("")
{
}
void page::setFileName(string newName) {
	fileName = newName;
}
string page::getFileName() {
	return(fileName);
}
void page::setCssFile(string newName) {
	cssFile = newName;
}
string page::getCssFile() {
	return(cssFile);
}
void page::addTag(string newTag) {
	tags.push_back(newTag);
}
void page::addTag(string newTag, int pos) {
	tags.insert(tags.begin()+pos, newTag);
}
void page::remTag(int pos) {
	if (tags.empty()) {
		std::cout << "Cannot erase empty vector" << endl;
		return;
	}
	if (pos < 0 || pos > tags.size()-1) {
		std::cout << "Invalid number for vector" << endl;
		return;
	}
	tags.erase(tags.begin() + pos);
}
vector <string> page::getTags() {
	return(tags);
}
void page::setPageName(string newName) {
	pageName = newName;
}
string page::getPageName() {
	return(pageName);
}

ostream& operator << (ostream& output, const page& currentPage) {
	output << "<!DOCTYPE html>\n<html><head>" << endl;
	if (currentPage.fileName != "") {
		output << "<title>" << currentPage.pageName << "</title>" << endl;
	}
	if (currentPage.cssFile != ""){
		output << "<link rel = \"stylesheet\" href = \"" << currentPage.cssFile << "\">" << endl;
	}
	output << "</head>\n<body>" << endl;
	for (string tag : currentPage.tags) {
		output << tag << endl;
	}
	output << "</body>\n</html>" << endl;
	return(output);
}
void page::clearPage() {
	fileName = "";
	cssFile = "";
	tags.clear();
	pageName = "";

}