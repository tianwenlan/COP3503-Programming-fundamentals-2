#include "BST.h"
#include <iostream>
using namespace std;

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