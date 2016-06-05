// lab4(tmp).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void forward(int top, int* in, int n)
{
	for (int j = 0; j<n; j++)
		if (in[j] == top)
		{
			cout << j << " ";
			forward(j, in, n);
		}
	cout << endl;
}


void back(int top, int* in, int n)
{
	for (int j = 0; j<n; j++)
		if (in[j] == top)
		{
			back(j, in, n);
		}
	if (top != -1) cout << top << " ";
	cout << endl;
}

void sim(int top, int* in, int n)
{
	int x = 0;
	for (int j = 0; j<n; j++)
		if (in[j] == top)
		{
			sim(j, in, n);
			if ((!x) && (top != -1)) cout << top << " ";
			x++;
		}
	if (x == 0)
	{
		cout << top << " ";
	}
	cout << endl;
}


int main()
{
	int N;
	cin >> N;
	int* in = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> in[i];
	}

	forward(-1, in, N);
	back(-1, in, N);
	sim(-1, in, N);

	delete in;
	return 0;
}
