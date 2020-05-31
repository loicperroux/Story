#include "Page.h"
#include <iostream>

using namespace std;

	
	/*Page::Page() {
	number = 0;
	}

	Page::Page(int num) {
		number = num;
	}
	*/
	void Page::setNumber(int num) {
		number = num;	
	}

	int Page::getNumber() {
		return number;
	}

	void Page::print() {
		cout << "page : " << number+1 << endl;
	}
