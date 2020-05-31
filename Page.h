#pragma once


class Page
{

		
protected:
	int number;


public:
	Page() { number = 0;}
	Page(int num) { number = num; }
	void setNumber(int num);
	int getNumber();
	virtual void print();

};

