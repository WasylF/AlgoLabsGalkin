// Wsl_F
#include <iostream>

using namespace std;

template <typename T>
class LinkedStack
{
private:
	class Node
	{
	public:
		T value;
		Node* prev;

	public:
		Node()
		{
			value = T();
			prev = NULL;
		}

		Node(T value, Node* prev)
		{
			this->value = value;
			this->prev = prev;
		}

		~Node()
		{
			value = T();
			prev = NULL;
		}

	};

private:
	Node *last;
	int size_ = 0;

public:
	LinkedStack()
	{
		last = NULL;
		size_ = 0;
	}

	void push(T value)
	{
		if (size_ == 0)
		{
			Node* newNode = new Node(value, NULL);
			last = newNode;
		}
		else
		{
			Node* newNode = new Node(value, last);
			last = newNode;
		}
		size_++;
	}


	T back()
	{
//		if (size_ == 0)
	//		throw out_of_range("Stack is empty");

		return last->value;
	}

	void pop()
	{
		//if (size_ == 0)
			//throw out_of_range("Stack is empty");

		if (size_ == 1)
		{
			delete last;
			size_ = 0;
			return;
		}

		Node* node = last;
		last = last->prev;
		delete node;
		size_--;
	}

	int size()
	{
		return this->size_;
	}

private:
	void print(ostream& out)
	{
		out << "size: " << size_ << endl;

		for (Node* cur = last; cur; cur = cur->prev)
			out << cur->value << " ";
		out << endl;
	}

};
