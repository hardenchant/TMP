// lab1(tmp).cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void scan(string s1, string s2) {
	int i = 1;
	ifstream F1(s1);
	while (!F1.eof()) {
		string s1, s2;
		bool bb = false;
		ifstream F2(s2);
		getline(F1, s1);
		while (!F2.eof()) {
			getline(F2, s2);
			if (s1 == s2) {
				bb = true;
			}
		}
		F2.close();
		if (bb == false) {
			cout << s1 << " " << i << " " << s1 << endl;
			i++;
		}
	}
	F1.close();
}

int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	scan(s1, s2);
	scan(s2, s1);
	system("pause");
	return 0;
}