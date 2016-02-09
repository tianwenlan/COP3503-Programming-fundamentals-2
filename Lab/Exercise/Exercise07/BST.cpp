#include <iostream>
#include <string>
#include "BST.h"

using namespace std;


Node::Node(){
	data = 0;
	left = NULL;
	right = NULL;
}

void Node::insert(int num){
	if(num<data){
		if(left==NULL){
			left=new Node();
			left->data=num;
			return;
		}else if(left!=NULL){
			left->insert(num);
		}
	}
	
	if(num>data){
		if(right==NULL)	{
		right=new Node();
		right->data=num;
		return;	
		}else if(right!=NULL){
			right->insert(num);
		}
	}
}

void Node::print_inorder(){
	if(left!=NULL){
	left -> print_inorder();
	}
	cout << data << " ";

	if(right!=NULL){
	right -> print_inorder();
	}
}


BST::BST(){
	root = NULL;
}

void BST::insert(int num){
	if(root == NULL){
		root = new Node();
		root->data = num;
	}else{
		root->insert(num);
	}
	return;

}


void BST::print_inorder(){
	if(root==NULL){
		cout << "Tree empty" << endl;
		return;
	}else{
	root->print_inorder();
	cout << "\n";
	return;
	}
}

int N;

void Node::find(int num){
	if(num==data){
//		cout << "Root " << num << " found" << endl;
		N=1;
	}else if (num<data){
		if(left!=NULL){
		left->find(num);
		}else{
//		cout << "Root " << num << " not found!" << endl;
		N=0;
		}
	}else{
		if(right!=NULL){
		right->find(num);
		}else{
//		cout << "Root " << num << " not found!" << endl;
		N=0;
		}
	}
//	return true;
}

bool BST::find(int num){
	if(root!=NULL){
		root->find(num);		
	}
	if(N==1){ 
		return true;
	}else {
		return false;
	}
}

void Node::print_from_value(int num){
	if(num==data){
		if(left!=NULL){
		left->print_from_value(left->data);
		}
		cout << data << " ";
		if(right!=NULL){
		right->print_from_value(right->data);
		}
	}else if (num<data){
		if(left!=NULL){
		left->print_from_value(num);
		}else{
		cout << "Node " << num << " not found!" << flush;
		}
	}else if (num > data){
		if(right!=NULL){
		right->print_from_value(num);
		}else{
		cout << "Node " << num << " not found!" << flush;
		}
	}

}


void BST::print_from_value(int num){
	if(root!=NULL){
		root->print_from_value(num);
		cout << "\n";
	}else{
		cerr << "Tree does not exist" << endl;
	}
}

