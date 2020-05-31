#include "Page_image.h"
#include "Page.h"
using namespace std;

Page_image::Page_image() {
	
	image = "";
}

Page_image::Page_image(int num) {
	string tmp = "";
	image= tmp;
	number = num;
}

Page_image::Page_image(int num, string img) {
	number = num;
	image = img;
}

void Page_image::print() {
	Page::print();
	cout << image << endl;
}

string Page_image::getImage() {
	return image;
}