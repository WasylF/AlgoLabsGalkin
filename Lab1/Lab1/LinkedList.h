// Wsl_F
#include <iostream>

using namespace std;

template <typename T>
class LinkedList
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
	LinkedList()
	{
		first = NULL;
		last = NULL;
		size_ = 0;
	}

	void add(T value)
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

	void add(int position, T value)
	{
	//	if (position<0 || position>size_)
//			throw out_of_range("wrong index!");


		if (position == size_)
		{
			add(value);
			return;
		}

		if (position == 0)
		{
			Node* newNode = new Node(value, NULL, first);
			if (first) first->prev = newNode;
			first = newNode;
		}
		else
		{
			Node* cur = first;
			for (int i = 1; i < position; i++)
				cur = cur->next;
			Node* newNode = new Node(value, cur, cur->next);
			cur->next = newNode;
			newNode->next->prev = newNode;
		}

		size_++;
	}

	void print(ostream& out)
	{
		out << "size: " << size_ << endl;

		for (Node* cur = first; cur; cur = cur->next)
			out << cur->value << " ";
		out << endl;
	}

	T get(int index)
	{
	//	if (index < 0 || index >= size_)
//			throw out_of_range("wrong index!");

		return getNode(index)->value;
	}

	void erase(int index)
	{
		//if (index < 0 || index >= size_)
			//throw out_of_range("wrong index!");

		Node* node = getNode(index);
		if (index == 0)
		{
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

		if (index + 1 == size_)
		{
			last = last->prev;
			last->next = NULL;
			delete node;
			size_--;
			return;
		}

		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		size_--;
	}

	int size()
	{
		return this->size_;
	}

private:

	Node* getNode(int index)
	{
//		if (index < 0 || index >= size_)
	//		throw out_of_range("wrong index!");

		Node *cur = first;
		for (int i = 1; i <= index; i++)
			cur = cur->next;

		return cur;
	}
};
