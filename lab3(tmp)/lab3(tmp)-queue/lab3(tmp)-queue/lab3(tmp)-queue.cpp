// lab3(tmp)-queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class queue {
private:
	string info;
	queue *next;
public:
	queue();
	~queue();
	void add(string data);
	void get();
	void del();
};
/**
\func constructor - initializing
*/
queue::queue()
{
	next = nullptr;
	info = "";
}
/**
\func destructor
*/
queue::~queue() {
	while (next != nullptr) {
		queue *temp = this;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}
}
/**
\func add function of queue - add obj in queue
*/
void queue::add(string data)
{
	queue *temp = this;
	/*if (temp->next == nullptr)
	{
	temp->next = new queue();
	}*/
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = new queue();
	temp->next->info = data;
}
/**
\func get function of queue - get first obj in queue
*/
void queue::get()
{
	if (next == nullptr) return;
	cout << next->info << endl;
}
/**
\func get function of queue - delete first obj in queue
*/
void queue::del()
{
	if (next == nullptr) return;
	if (next->next == nullptr)
	{
		delete next;
		next = nullptr;
	}
	else
	{
		queue *temp = next;
		next = next->next;
		delete temp;
	}
}

/**
\func main function in programm
*/
int main()
{
	queue head;
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
	return 0;
}