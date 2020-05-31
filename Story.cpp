// Story.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <vector>
#include "Page.h"
#include "Page_text.h"
#include "Page_image.h"
#include "Page_full.h"

using namespace std;

void getImage(string& str) {

	string  adder = "";
	while (adder.compare("stop") != 0)
	{
		str += adder + "\n";
		getline(cin, adder);
	}
}

void getText(string& str) {
	getline(cin, str);           // the first is to clear the buffer, as fflush in C
	cout << "> ";
	getline(cin, str);			 // this is the real getline who take the input from the user
}


void addPagePt(vector<Page_text*> & tmp,int nb){                      //create a page and add it 
	
	string txt;
	cout << "- Give the text for the " << nb+1 << " page :" << endl;
	getText(txt);
	Page_text* p1 = new Page_text(nb, txt);

	tmp[nb] = p1;
}

void addPagePi(vector<Page_image*> &tmp, int nb) {                      //create a page and add it 

	string img;
	cout << "- Give the image for the " << nb+1 << " page : \n(write 'stop' when you finished the image)" << endl;
	getImage(img);
	Page_image* p1 = new Page_image(nb,img);

	tmp[nb] = p1;
}

void addPagePf(vector<Page_full*> &tmp, int nb) {                      //create a page and add it 

	string txt;
	string img;
	cout << "- Give the text for the page " << nb+1 <<" :" << endl;
	getText(txt);
	cout << "- Give the image for this page :  \n(write 'stop' when you finished the image)" << endl;
	getImage(img);
	Page_full* p1 = new Page_full(nb, txt, img);

	tmp[nb] = p1;
}


int pageChoice(int p) {    // pt, pi, pf

	int typage = 0;
	while (typage < 1 || typage > 3) {
		cout << "\nWhat kind of page do you want to add for the page "<< p+1 <<" ?" << endl << "type :" << endl;
		cout << "1   for a page with only text" << endl;
		cout << "2   for a page with only image" << endl;
		cout << "3   for a page with both (image and text)" << endl << ">";
		cin >> typage;
		cout << endl;
	}
	return typage;
}

void removePage(int num) {

}

void readStory(vector<int> & tyPage, vector<Page_text*> & pt, vector<Page_image*> & pi, vector<Page_full*> & pf, int nbPage, string name ) {

	system("cls");
	cout << "================================ " << name << "================================ " << endl;
	for (int i = 0; i < nbPage; i++) {

		if (tyPage[i] == 1)
			pt[i]->print();
		else if (tyPage[i] == 2)
			pi[i]->print();
		else
			pf[i]->print();
		cout << endl;
	}
	cout << "========================= end of " << name << "================================ " << endl << endl;
}

void storeStory(vector<int>& tyPage, vector<Page_text*>& pt, vector<Page_image*>& pi, vector<Page_full*>& pf, int nbPage) {


	string nom, tmp, c;
	cout << "Do you want to save your story ? y/n\n>";
	cin >> c;
	if (c == "n")
		return;
	cout << "Give the file name :\n>";
	cin >> nom;
	cout << endl;
	ofstream f(nom);
	if (f.is_open())
	{
		for (int i = 0; i < nbPage; i++) {

			if (tyPage[i] == 1) {
				tmp = pt[i]->getText();
				f << tmp;
			} else if (tyPage[i] == 2) {
				tmp = pi[i]->getImage();
				f << tmp;
			}
			else {
				tmp = pf[i]->getImage();
				f << tmp;
				tmp = pf[i]->getText();
				f << tmp;
			}
		}

		f.close();
	}
	else
		cout << "Impossible to open the file" << endl;
}




int main()
{
	int nbPage, typage;
	string name;
	

	cout << "Give the page's number requiere to create the story :\n> ";
	cin >> nbPage;
	vector<int> tyPage(nbPage);							// 1 = pt, 2 = pi, 3 = pf
	vector<Page_text*> pt(nbPage);
	vector<Page_image*> pi(nbPage);
	vector<Page_full*> pf(nbPage);

	
	cout << "Give a name to your story" << endl;
	getText(name);

	
	// création des pages 
	for (int i = 0; i < nbPage; i++) {
		
		typage = pageChoice(i);

		if (typage == 1) {
			addPagePt(pt, i);
			tyPage[i] = typage;
		}
		else if (typage == 2) {
			addPagePi(pi, i);
			tyPage[i] = typage;
		}
		else {
			addPagePf(pf, i);
			tyPage[i] = typage;
		}

	}

	// affichage de l'histoire
	
	readStory(tyPage, pt, pi, pf, nbPage, name);
	storeStory(tyPage, pt, pi, pf, nbPage);

}