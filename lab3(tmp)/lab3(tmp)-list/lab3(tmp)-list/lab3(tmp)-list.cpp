// lab3(tmp)-list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;


class list {
private:
	string info;
	list *next;
public:
	list();
	~list();
	void add(int i, string data);
	void get(int i);
	void del(int i);
};
/**
\func constructor - initializing
*/
list::list()
{
	next = nullptr;
	info = "";
}
/**
\func ~list function of list - deleted all objects in list
*/

list::~list()
{
	list *temp, *temp2;
	temp2 = nullptr;
	temp = this;
	while (this->next != nullptr)
	{
		while (temp->next != nullptr)
		{
			temp2 = temp;
			temp = temp->next;
		}
		delete temp;
		temp2->next = nullptr;
	}
}
/**
\func add function of list - add object on position in list
*/
void list::add(int i, string data)
{
	if (i == 0)
	{
		this->info = data;
	}
	else
	{
		if (this->next == nullptr)
		{
			this->next = new list();
			this->next->add(i - 1, data);
		}
		else
		{
			this->next->add(i - 1, data);
		}
	}
}
/**
\func get function of list - get choosen obj from list
*/
void list::get(int i)
{
	if (next == nullptr && info == "")  //чекаем пустой список или нет
	{
		cout << "list is empty" << endl;
		return;
	}
	bool empty = false; //чекаем создан элемент или нет
	list *pp = this;
	for (int j = 0; j < i; j++)
	{
		if (pp->next == nullptr&& j != 0)
		{
			empty = true;
			break;
		}
		pp = pp->next;
	}
	if (!empty)
	{
		cout << pp->info.data() << endl;
	}
	else
	{
		cout << "Index not created" << endl;
	}

}
/**
\func del function of list - del choosen obj from list
*/
void list::del(int i)
{
	list *p = this;
	list *pp;
	if (next == nullptr && info == "")
	{
		cout << "list is empty" << endl;
		return;
	}
	if (i == 0)   //удаление со сдвигом т.е. был 5 элемент = 10, при удалении 3 элемента, 4 элемент = 10
	{			 //а 5 больше не существует
		p->info = "";
	}
	else
	{
		for (int j = 0; j < i - 1; j++)
		{

			p = p->next;
		}
		pp = p;			//сохраняем предыдущий элемент
		p = p->next;
		pp->next = p->next;  //меняем указатель на предыдущем на указатель на следующий
		delete p;
	}

}

/**
\func main function in programm
*/
int main()
{

	list head;
	int N;
	int j;
	cin >> N;
	string data;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		if (data == "add")
		{
			cin >> j;
			cin >> data;
			head.add(j, data);
		}
		if (data == "get")
		{
			cin >> j;
			head.get(j);
		}
		if (data == "del")
		{
			cin >> j;
			head.del(j);
		}

	}
	return 0;
}