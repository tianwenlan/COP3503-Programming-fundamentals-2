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
	~Node();
	void insert(int);
	void print_inorder();
	int sum();
	int size();
	Node* remove(int);
	void clear();
	int findSuccessor(int);


};

class BST{
	public:
	Node *root;
	
	BST();
	~BST();
	void insert(int);
	void print_inorder();
	int sum();
	int size();
	float average();
	void remove(int);
	void clear();
};

#endif
