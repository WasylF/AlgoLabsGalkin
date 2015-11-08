#include <vector>
#include <iostream>


using namespace std;

typedef vector<int> vi;
#define pb(x) push_back(x)

class MaxHeap
{
private:
	int n;
	vi a;
public:
	MaxHeap();
	void build(int* b, int n0);
	int getMax();
	void add(int val);
	void deleteMax();
	void print();

private:
	void heapfy(int v);
};
