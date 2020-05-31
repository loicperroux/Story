#include "Page_full.h"
#include "Page.h"
using namespace std;

Page_full::Page_full() {
	string tmp = "";
	text = tmp;
}

Page_full::Page_full(int num) {
	string tmp = "";
	text = tmp;
	number = num;
}

Page_full::Page_full(int num, string txt, string img) {
	number = num;
	text = txt;
	image = img;
}

void Page_full::print() {
	Page::print();
	cout << image << endl << "\n";
	cout << text << endl;
}

string Page_full::getText() {
	return text;
}

string Page_full::getImage() {
	return image;
}