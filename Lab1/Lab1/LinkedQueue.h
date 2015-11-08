// Wsl_F
#include <iostream>

using namespace std;

template <typename T>
class LinkedQueue
{
private:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;

	public:
		Node()
		{
			value = T();
			next = NULL;
			prev = NULL;
		}

		Node(T value, Node* prev, Node* next)
		{
			this->value = value;
			this->prev = prev;
			this->next = next;
		}

		~Node()
		{
			value = T();
			prev = NULL;
			next = NULL;
		}

	};

private:
	Node *first;
	Node *last;
	int size_ = 0;

public:
	LinkedQueue()
	{
		first = NULL;
		last = NULL;
		size_ = 0;
	}

	void push(T value)
	{
		if (size_ == 0)
		{
			Node* newNode = new Node(value, NULL, NULL);
			first = newNode;
			last = newNode;
		}
		else
		{
			Node* newNode = new Node(value, last, NULL);
			last->next = newNode;
			last = newNode;
		}
		size_++;
	}

	void pop()
	{
//		if (size_ == 0)
	//		throw out_of_range("queue is empty");

		Node* node = first;
		if (size_ == 1)
		{
			first = NULL;
			last = NULL;
			delete node;
			size_ = 0;
			return;
		}

		first = first->next;
		first->prev = NULL;
		delete node;
		size_--;
		return;
	}

	T front()
	{
		//if (size_ == 0)
			//throw out_of_range("queue is empty");

		return first->value;
	}

	int size()
	{
		return this->size_;
	}

private:
	void print(ostream& out)
	{
		out << "size: " << size_ << endl;

		for (Node* cur = first; cur; cur = cur->next)
			out << cur->value << " ";
		out << endl;
	}
};
