#pragma once
#include "Page.h"
#include <iostream>
using namespace std;

class Page_text : public Page
{
private:
	string text;

public:
	
	Page_text();
	Page_text(int num);
	Page_text(int num, string txt);
	void print();
	string getText();
};

