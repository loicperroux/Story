#pragma once
#include "Page.h"
#include <iostream>
using namespace std;

class Page_image : public Page
{
private:
	string image;

public:

	Page_image();
	Page_image(int num);
	Page_image(int num, string image);
	void print();
	string getImage();
};

