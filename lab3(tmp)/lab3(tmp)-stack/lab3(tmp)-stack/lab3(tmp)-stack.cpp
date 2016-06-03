// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class stack {
private:
	string info;
	stack *next;
public:
	stack();
	void add(string data);
	void get();
	void del();
	void delstack();
};
/**
\func constructor - initializing
*/
stack::stack()
{
	next = nullptr;
	info = "";
}
/**
\func add function of stack - add obj in stack
*/
void stack::add(string data)
{
	stack *temp = this;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = new stack();
	temp->next->info = data;
}
/**
\func get function of stack - get last obj added in stack
*/
void stack::get()
{
	stack *temp = this;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	cout << temp->info << endl;
}
/**
\func del function of stack - del last obj added in stack
*/
void stack::del()
{
	if (next == nullptr)
	{
		info = "";
		return;
	}
	stack *temp = this;
	while (temp->next->next != nullptr)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
}
/**
\func delstack function of stack - deleted all objects in stack
*/
void stack::delstack()
{
	stack *temp = this;
	while (next != nullptr)
	{
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		delete temp->next;
	}
}
/**
\func main function of programm
*/
int main()
{
	stack head;
	int N;
	cin >> N;
	string data;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		if (data == "add")
		{
			cin >> data;
			head.add(data);
		}
		if (data == "get")
		{
			head.get();
		}
		if (data == "del")
		{
			head.del();
		}

	}
	head.delstack();
	return 0;
}