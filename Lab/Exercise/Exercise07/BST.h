#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>

using namespace std;


class Node{
	public:
	int data;
	Node *left;
	Node *right;
	
	Node();
	void insert(int);
	void print_inorder();
	void find(int);
	void print_from_value(int);
};

class BST{
	public:
	Node *root;
	
	BST();
	void insert(int);
	void print_inorder();
	bool find(int);
	void print_from_value(int);
};

#endif
