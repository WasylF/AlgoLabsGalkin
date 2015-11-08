// Wsl_F
#include <bits/stdc++.h>

//#include "stdafx.h"
#include "MaxHeap.h"
#include "BinarySearchTree.h"

void testHeap()
{
	MaxHeap mH;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	mH.build(a, 10);
	mH.print();
	mH.getMax();
	int type;
	int t;
	while (cin >> type)
	{
		if (type == 0)
		{
			cout << mH.getMax() << endl;
		}
		else if (type == 1)
		{
			cout << mH.getMax() << endl;
			mH.deleteMax();
			cout << mH.getMax() << endl;
		}
		else if (type == 3)
		{
			cin >> t;
			mH.add(t);
		}
		//        cout<<endl<<endl;
		//      mH.print();
	}

	return;
}

void BST()
{
	BinarySearchTree<int> bst;
	bst.add(0);

	for (int i = 1; i < 10; i++)
		bst.add(i);

	bst.preorder();
	cout << endl;
	bst.rebalance();
	cout << endl;

	bst.preorder();
	cout << endl;
	bst.postorder();
	cout << endl;
	bst.inorder();
	cout << endl;

	bst.rebalance();

	bst.preorder();
	cout << endl;
	bst.postorder();
	cout << endl;
	bst.inorder();
	cout << endl;

}

void testIsomorfizm()
{
	BinarySearchTree<int> bst1;
	BinarySearchTree<int> bst2;
	BinarySearchTree<int> bst3;
	BinarySearchTree<int> bst4;

	for (int i = 1; i <= 10; i++)
		bst1.add(i);

	for (int i = 11; i <= 20; i++)
		bst2.add(i);

	for (int i = 20; i > 10; i--)
		bst3.add(i);

	for (int i = 5; i >= 1; i--)
		bst4.add(i);
	for (int i = 6; i <=10; i++)
		bst4.add(i);

	cout << bst1.isomorfizm(bst2) << endl;
	cout << bst1.isomorfizm(bst3) << endl;
	cout << bst1.isomorfizm(bst4) << endl;


}

int main()
{
	//testHeap();
	//BST();

	testIsomorfizm();

	system("pause");

    return 0;
}

