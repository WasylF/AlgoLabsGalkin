#include <vector>
#include <iostream>
#include "MaxHeap.h"

using namespace std;

typedef vector<int> vi;
#define pb(x) push_back(x)


MaxHeap::MaxHeap()
{
	n = 0;
}

void MaxHeap::build(int* b, int n0)
{
	n = n0;
	//a.capacity(n);
	a.clear();
	for (int i = 0; i < n; i++)
		a.pb(b[i]);

	for (int i = n / 2; i >= 0; i--)
		heapfy(i);
}

int MaxHeap::getMax()
{
	return a[0];
}

void MaxHeap::add(int val)
{
	if (n<a.size()) a[n] = val;
	else a.pb(val);
	n++;
	int i = n - 1;
	while (a[i]>a[i / 2])
	{
		swap(a[i], a[i / 2]);
		i /= 2;
	}
}

void MaxHeap::deleteMax()
{
	if (n == 0) return;
	a[0] = a[--n];
	heapfy(0);
}

void MaxHeap::print()
{
	cout << n << "(" << a.size() << "): ";
	for (int i = 0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}


void MaxHeap::heapfy(int v)
{
	if (2 * v + 1 >= n) return;
	if (2 * v + 2 == n)
	{
		if (a[v] < a[2 * v + 1]) swap(a[v], a[2 * v + 1]);
		return;
	}

	if (a[v] > a[2 * v + 1] && a[v] > a[2 * v + 1]) return;
	
	if (a[2 * v + 1] > a[2 * v + 2])
	{
		swap(a[v], a[2 * v + 1]);
		heapfy(2 * v + 1);
	}
	else
	{
		swap(a[v], a[2 * v + 2]);
		heapfy(2 * v + 2);
	}
}