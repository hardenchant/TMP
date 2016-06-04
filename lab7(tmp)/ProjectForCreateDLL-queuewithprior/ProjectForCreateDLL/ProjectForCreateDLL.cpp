// ProjectForCreateDLL.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#define EXPORT extern "C" __declspec(dllexport)

using namespace std;

EXPORT void get(vector<int> *dtree)
{
	cout << dtree[0][0] << endl;
	cout << "Called get" << endl;
}

EXPORT void  add(vector<int> *dtree, int arg) {

	int i;
	if (dtree[0].size() == 0) {
		dtree[0].insert(dtree[0].begin(), arg);
	}
	else {
		for (i = 0; i < dtree[0].size(); i++) {
			if (arg <= dtree[0][i]) {
				dtree[0].insert(dtree[0].begin() + i, arg);
				break;
			}
		}
		if (i == dtree[0].size())
			dtree[0].push_back(arg);
	}
	cout << "called add" << endl;
}
EXPORT void  del(vector<int> *dtree) {
	dtree[0].erase(dtree[0].begin());
	cout << "Called del" << endl;
}