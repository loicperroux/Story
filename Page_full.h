#pragma once
#include "Page.h"
#include <iostream>
using namespace std;

class Page_full : public Page
{
private:
	string text;
	string image;

public:

	Page_full();
	Page_full(int num);
	Page_full(int num, string txt, string img);
	void print();
	string getText();
	string getImage();
};
