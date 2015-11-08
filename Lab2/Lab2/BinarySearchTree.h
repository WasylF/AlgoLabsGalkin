#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "TreeNode.h"

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() { root = NULL; size = 0; }
	void add(T value)
	{
		size++;
		if (!root)
		{
			root = new TreeNode<T>(value);
			return;
		}

		TreeNode<T>* cur = root;
		while (1)
		{
			if (value > cur->val)
			{
				if (cur->right) cur = cur->right;
				else
				{
					cur->right = new TreeNode<T>(value);
					return;
				}
			}
			else
			{
				if (cur->left) cur = cur->left;
				else
				{
					cur->left = new TreeNode<T>(value);
					return;
				}
			}
		}

	}
	void read(string filename)
	{
		ifstream in(filename);
		string s;

		T val;
		while (in >> val)
			add(val);


		in.close();
	}

	void inorder() { inorder(root); }
	void preorder() { preorder(root); }
	void postorder() { postorder(root); }

	void print()
	{//друк результату прямого обходу в дужковій формі
		print(root);
		cout << endl;
	}

	T* get(TreeNode<T>* cur, T* ar)
	{
		if (!cur) return ar;

		ar[0] = cur->val;
		T* next = get(cur->left, ar + 1);
		next = get(cur->right, next);

		return next;
	}

	void del(TreeNode<T>* cur)
	{
		if (!cur) return;
//		del(cur->left);
	//	del(cur->right);
		//cout << "deleted: " << cur->val << endl;
		delete cur;
		size = 0;
		root = NULL;
	}

	void rebalance()
	{
		T* ar = new T[size];
		int n = size;
		get(root, ar);
		sort(ar, ar + size);
		del(root);

		rebalance(ar, n);
		delete[] ar;
	}

	bool isomorfizm(BinarySearchTree<T> t2)
	{
		return isomorfizm(root, t2.getRoot());
	}


private:
	TreeNode<T>* getRoot()
	{
		return root;
	}

	int size;
	TreeNode<T>* root;

	bool isomorfizm(TreeNode<T>* root1, TreeNode<T>* root2)
	{
		if (root1 == root2) return true;

		if (!root1 || !root2) return false;

		if (isomorfizm(root1->left, root2->left)  && isomorfizm(root1->right,root2->right)) return 1;
		if (isomorfizm(root1->left, root2->right) && isomorfizm(root1->right,root2->left )) return 1;

		return 0;
	}

	void print(TreeNode<T>* cur)
	{
		if (!cur) return;
		cout << cur->val << " ";
		cout << "(";
		print(cur->left);
		print(cur->right);
		cout << ")";
	}

	void processVertex(TreeNode<T>* cur)
	{
		if (cur) cout << cur->val << " ";
	}

	void inorder(TreeNode<T>* cur)
	{//зворотній
		if (!cur) return;
		preorder(cur->left);
		processVertex(cur);
		preorder(cur->right);
	}

	void preorder(TreeNode<T>* cur)
	{//прямий
		if (!cur) return;
		processVertex(cur);
		preorder(cur->left);
		preorder(cur->right);
	}

	void postorder(TreeNode<T>* cur)
	{//кінцевий
		if (!cur) return;
		preorder(cur->left);
		preorder(cur->right);
		processVertex(cur);
	}

	void rebalance(T* ar, int n)
	{
		if (n == 0) return;
		int mid = n / 2;
		add(ar[mid]);
		rebalance(ar, mid);
		rebalance(ar + mid + 1, n - mid - 1);
	}

	
};