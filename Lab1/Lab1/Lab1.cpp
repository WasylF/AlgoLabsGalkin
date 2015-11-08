// Wsl_F
//#include "stdafx.h"
#include <bits/stdc++.h>

#include <string>
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

using namespace std;

void testLinkedList()
{
	LinkedList<int> list;

	cout << "TEST linked list" << endl << endl;
	cout << endl << "******************************************" << endl << "push back" << endl << endl;
	for (int i = 6; i < 10; i++)
	{
		list.add(i);
		list.print(cout);
	}

	cout << endl << "******************************************" << endl << "push front" << endl << endl;
	list.add(0, 0);
	list.print(cout);

	cout << endl << "******************************************" << endl << "insert" << endl << endl;
	for (int i = 1; i < 6; i++)
	{
		list.add(i, i);
		list.print(cout);
	}

	cout << endl << "******************************************" << endl << "push back" << endl << endl;
	for (int i = 10; i <= 15; i++)
	{
		list.add(i, i);
		list.print(cout);
	}

	cout << endl << "******************************************" << endl << "get by index" << endl << endl;
	for (int i = 0; i <= 15; i++)
		cout << list.get(i) << " ";
	cout << endl;

	cout << endl << "******************************************" << endl << "erase front" << endl << endl;
	for (int i = 0; i <= 5; i++)
	{
		list.erase(0);
		list.print(cout);
	}

	cout << endl << "******************************************" << endl << "erase inner" << endl << endl;
	for (int i = 4; i >= 0; i--)
	{
		list.erase(i);
		list.print(cout);
	}


	cout << endl << "******************************************" << endl << "erase back" << endl << endl;
	for (int i = list.size() - 1; i >= 0; i--)
	{
		list.erase(i);
		list.print(cout);
	}

	system("pause");
}

void testLinledStack()
{
	LinkedStack<char> stack;

	cout << "TEST linked stack" << endl << endl;
	cout << endl << "******************************************" << endl << "push back" << endl << endl;
	for (char i = 'a'; i <= 'e'; i++)
	{
		stack.push(i);
		cout<<stack.back()<<endl;
	}

	cout << endl << "******************************************" << endl << "pop back" << endl << endl;
	while (stack.size())
	{
		cout << stack.back() << endl;
		stack.pop();
	}

	system("pause");
}

void testLinledQueue()
{
	LinkedQueue<string> queue;

	cout << "TEST linked queue" << endl << endl;
	cout << endl << "******************************************" << endl << "push back" << endl << endl;
	string s = "";
	for (char i = 'a'; i <= 'e'; i++)
	{
		s += i;
		queue.push(s);
		cout << queue.front() << endl;
	}

	cout << endl << "******************************************" << endl << "pop front" << endl << endl;
	while (queue.size())
	{
		cout << queue.front() << endl;
		queue.pop();
	}

	system("pause");
}

int main()
{
	testLinkedList();

	testLinledStack();

	testLinledQueue();

	return 0;
}

