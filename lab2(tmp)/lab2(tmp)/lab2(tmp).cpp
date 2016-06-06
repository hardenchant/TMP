// lab2(tmp).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string temp;
	ifstream file("in.txt");
	getline(file, temp, '\0');
	file.close();
	int i = 0;

	while (i < temp.length())
	{
		if ((temp[i] == '/') && (temp[i + 1] == '*') && (temp[i + 2] == '*'))
		{
			i += 3;
			while (temp[i] != '\\')
			{
				i++;
			}

			while ((temp[i] != ' ') && (temp[i] != '\n'))
			{
				i++;
			}
			i++;

			while ((temp[i] != '*') || (temp[i + 1] != '/'))
			{
				if (temp[i] == '\n') cout << ' ';
				else cout << temp[i];
				i++;
			}
			cout << endl;
			i++;
		}
		i++;
	}
	return 0;
}
