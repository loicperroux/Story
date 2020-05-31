#include "Page_text.h"
#include "Page.h"
using namespace std;

Page_text::Page_text() {
	string tmp = "";
	text = tmp;
}

Page_text::Page_text(int num) {
	string tmp = "";
	text = tmp;
	number = num;
}

Page_text::Page_text(int num, string txt) {
	number = num;
	text = txt;
}

void Page_text::print() {
	Page::print();
	cout << text << endl;
}

string Page_text::getText() {
	return text;
}
