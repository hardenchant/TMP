// lab6(tmp).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int v;
	int e;
	int n;

	cin >> v;
	cin >> e;
	cin >> n;

	bool* income;
	income = new bool[v];

	int* rasst;
	rasst = new int[v];

	int** graf;
	graf = new int*[v];
	for (int i = 0; i < v; i++)
	{
		graf[i] = new int[v];
	}


	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			graf[i][j] = 0;

		}
	}

	for (int i = 0; i < e; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		cin >> graf[v1][v2];
	}

	for (int i = 0; i<v; i++)
	{
		rasst[i] = INT_MAX;
		income[i] = false;
	}

	rasst[n] = 0;

	int u = 0;

	for (int i = 0; i < (v - 1); i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < v; j++)
		{
			if (!income[j] && (rasst[j] <= min))
			{
				min = rasst[j];
				u = j;
			}
		}
		income[u] = true;

		for (int k = 0; k < v; k++)
		{
			if (!income[k] && graf[u][k] && (rasst[u] != INT_MAX) && ((rasst[u] + graf[u][k]) < rasst[k]))
			{
				rasst[k] = rasst[u] + graf[u][k];
			}
		}
	}
	cout << endl << endl;
	for (int i = 0; i < v; i++)
		cout << rasst[i] << "  ";

	return 0;
}