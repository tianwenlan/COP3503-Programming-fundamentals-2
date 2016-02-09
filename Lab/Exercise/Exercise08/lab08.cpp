#include <iostream>
#include <string>

using namespace std;


class Node{
	public:
	int data;
	Node *left;
	Node *right;
	
	Node();
//	~Node();
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
//	~BST();
	void insert(int);
	void print_inorder();
	int sum();
	int size();
	float average();
	void remove(int);
	void clear();
};

Node::Node(){
	data = 0;
	left = NULL;
	right = NULL;
}
/*
Node::~Node(){
	cout << "I am dying!!!" << endl;
	delete left;
	delete right;
}
*/
void Node::insert(int num){
	if(num<data){
		if(left==NULL){
			left=new Node();
			left->data=num;
			return;
			delete left;
		}else if(left!=NULL){
			left->insert(num);
		}
	}
	
	if(num>data){
		if(right==NULL)	{
		right=new Node();
		right->data=num;
		return;	
		delete right;
		}else if(right!=NULL){
			right->insert(num);
		}
	}
}



Node* Node::remove(int num){

	if(num < data){
		if(left==NULL){
			return this;
		}else{
			left = left ->remove(num);
			return left;
		}
	}else if (num > data){
		if(right==NULL){
			return this;
		}else{
			right = right ->remove(num);
			return right;
		}
	}else{
		//case1: leaf
		if(right==NULL && left ==NULL){
			delete this;
			cout<<num<<" has been removed from the Tree."<<endl;
			return NULL;

		//cast2: has one child
		}else if(left == NULL && right!=NULL){
			Node * r = right;
			delete this;
			return r;
		}else if(right == NULL && left!=NULL){
			Node * l = left;
			delete this;
			return l;

		//case3: hase two children
		}else{
			data = findSuccessor(num);  
			cout << "successor:" << data << endl;
			right=right->remove(data);
			return right;
		}
	}
}

void BST::remove(int num){
	if(root==NULL){
		cout << "Tree empty" << endl;
		return;
	}else if(root->data==num){
		Node *temp;
		temp = root;
		temp->data = root->findSuccessor(num);
		delete root;
		temp->right->remove(num);
		root = temp;
		delete temp;
	}else{
		root->remove(num);
	}
}


int Node::findSuccessor(int num){

	Node * temp;

	if (num == data && right !=NULL){
		temp = right;
		while(temp->left!=NULL){
			temp = temp->left;
		}

	return temp->data;


	}else{
		return 0;
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

int Node::size(){
	int size =1;
	if(left!=NULL){
	size +=left->size();
	}

	if(right!=NULL){
	size +=right->size();
	}

	return size;
}

int Node::sum(){
	int sum =0;
	if(left!=NULL){
	sum+=left -> sum();
	}

	sum +=data;

	if(right!=NULL){
	sum+=right -> sum();
	}

	return sum;
}


void Node::clear(){
	if(left!=NULL){
//		left->clear();
		delete left;
	}

	if(right!=NULL){
//		right->clear();
		delete right;
	}
}



BST::BST(){
	root = NULL;
}

/*
BST::~BST(){
	cout << "I am dying!!!" << endl;
	delete root;
}
*/

void BST::insert(int num){
	if(root == NULL){
		root = new Node();
		root->data = num;
	}else{
		root->insert(num);
	}
	return;
	delete root;

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

int BST::size(){
	int size =0;
	if(root==NULL){
		cout << "Tree empty" << endl;
		return 0;
	}else{
	size = root->size();
//	cout << "size: " << size << endl;
	return size;
	}
}


int BST::sum(){
	int sum =0;
	if(root==NULL){
		cout << "Tree empty" << endl;
		return 0;
	}else{
	sum = root->sum();
//	cout << "sum: "<<sum << endl;
	return sum;
	}
}

float BST::average(){
	float average = 0;

	average = ((float)root->sum())/((float)root->size());

//	cout << "average: "<< average << endl;

	return average;
}

void BST::clear(){
	if (root==NULL){
		return;
	}else{
	root->clear();
	delete root;
	root=NULL;
	}
}

/*
int main(){
    BST * bst = new BST();
	Node node;
    int test[11] = {6,4,12,2,5,9,7,8,10,13,1};

	for (int i=0; i<11;i++){
		bst->insert(test[i]);
	}

	bst->size();
	bst->sum();
	bst->average();

	bst->print_inorder();
	bst->remove(7);
//	bst->print_inorder();
//	bst->remove(9);
	bst->print_inorder();
}

*/

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(int * nums, int n){
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(nums[j] < nums[i])
                swap(nums[j], nums[i]);
}

void push_to_back(int * nums, int n, int a){
    for(int i = 0;i<n;i++)
        if(nums[i] == a){
            for(int j=i;j<n-1;j++)
                nums[j] = nums[j+1];
            i = n;
        }

    sort(nums, n-1);
}

void test(BST * bst, int * nums, int n, int leaf, int root, int two, int one){
    static int test_no = 1;
    int count = 0;
    int nums_sorted[n];
    for(int i=0;i<n;i++){
        count += nums[i];
        nums_sorted[i] = nums[i];
    }
    sort(nums_sorted, n);

    cout << "\n\n\n" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                 TEST " << test_no++ << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "-------------\nTesting insert:\n-------------" << endl;
    cout << "  Inserting ";
    for(int i=0;i<n;i++){
        bst->insert(nums[i]);
        if(i < 20) cout << nums[i] << ", " << flush;
    }
    cout << "\n  Insert completed" << endl;


    cout << "-------------\nTesting sum/size/average:\n-------------" << endl;
    cout << "  sum : " << (bst->sum() == count ? "good" : "FAILED") << endl;
    cout << "  size: " << (bst->size() == n ? "good" : "FAILED") << endl;
    cout << "  avg : " << "Expected: " << ((float)count/n) << "\n        Received: " << bst->average() << endl;

    
    cout << "-------------\nTesting remove:\n-------------" << endl;

    cout << "  Removing " << leaf << endl;
    bst->remove(leaf);
    push_to_back(nums_sorted, n, leaf);
    cout << "  Expected: "; 
    for(int i=0;i<n-1;i++){
        cout << nums_sorted[i] << " " << flush;
    }
    cout << "\n  Received: ";
    bst->print_inorder();

    cout << "\n  Removing " << two << endl;
    bst->remove(two);
    push_to_back(nums_sorted, n-1, two);
    cout << "  Expected: "; 
    for(int i=0;i<n-2;i++){
        cout << nums_sorted[i] << " " << flush;
    }
    cout << "\n  Received: ";
    bst->print_inorder();

    cout << "\n  Removing " << one << endl;
    bst->remove(one);
    push_to_back(nums_sorted, n-2, one);
    cout << "  Expected: "; 
    for(int i=0;i<n-3;i++){
        cout << nums_sorted[i] << " " << flush;
    }
    cout << "\n  Received: ";
    bst->print_inorder();

    cout << "\n  Removing " << root << endl;
    bst->remove(root);
    push_to_back(nums_sorted, n-3, root);
    cout << "  Expected: "; 
    for(int i=0;i<n-4;i++){
        cout << nums_sorted[i] << " " << flush;
    }
    cout << "\n  Received: ";
    bst->print_inorder();

    
    cout << "-------------\nTesting clear:\n-------------" << endl;
    bst->clear();
    cout << "  Received: ";
    bst->print_inorder();
    cout << endl;
}   

int main(){
    BST * bst = new BST();
    int test1[] = {6,4,5,2,8,10};
    test(bst, test1, 6, 10, 6, 4, 5);

    BST * bst2 = new BST();
    int test2[1] = {5};
    test(bst2, test2, 1, 5, 5, 5, 5);

    BST * bst6 = new BST();
    int test6[7] = {8, 4, 2, 6, 12, 10, 14};
    test(bst6, test6, 7, 2, 8, 12, 4);

    BST * bst4 = new BST();
    int test4[10] = {-2, 4, -6, 8, -10, 12, -14, 16, -18, 20};
    test(bst4, test4, 10, -2, 8, -6, 4);

    BST * bst5 = new BST();
    int test5[20] = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
    test(bst5, test5, 10, 2, 20, 10, 12);
}


