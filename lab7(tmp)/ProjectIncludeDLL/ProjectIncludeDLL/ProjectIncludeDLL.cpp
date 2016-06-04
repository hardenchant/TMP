// ProjectIncludeDLL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

typedef void(*addfunc)(vector<int> *dtree, int arg);
typedef void(*delgetfunc)(vector<int> *dtree);


vector<int> dtree;


int main()
{
	cout << "DLL name:";
	string dllcom;
	cin >> dllcom;

	HINSTANCE hMyDll;
	hMyDll = LoadLibraryA(dllcom.c_str());
	if (hMyDll == NULL) {
		cout << "Not loaded" << endl;
		return 1;
	}
	cout << "Loaded" << endl;
	addfunc add;
	delgetfunc del;
	delgetfunc get;

	add = (addfunc)GetProcAddress((HMODULE)hMyDll, "add");
	del = (delgetfunc)GetProcAddress((HMODULE)hMyDll, "del");
	get = (delgetfunc)GetProcAddress((HMODULE)hMyDll, "get");

	if (get == NULL || del == NULL || get == NULL)
	{
		cout << "error" << endl;
	}

	string command;
	int n;
	int arg;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == "add")
		{
			cin >> arg;
			add(&dtree, arg);
		}
		if (command == "get")
		{
			get(&dtree);
		}
		if (command == "del")
		{
			del(&dtree);
		}
	}
	FreeLibrary((HMODULE)hMyDll);
	return 0;
}


