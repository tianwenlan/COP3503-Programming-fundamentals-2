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

void test(BST * bst, int * nums, int n, int middle1, int middle2, int left, int right){
    static int test_no = 1;
    int nums_sorted[n];
    for(int i=0;i<n;i++)
        nums_sorted[i] = nums[i];
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

    if(n < 20){
        cout << "\n-------------\nTesting in_order:\n-------------" << endl;
        cout << "  Expected: " << flush;
        for(int i=0;i<n;i++){
            cout << nums_sorted[i] << " " << flush;
        }
        cout << "\n  Received: " << flush;
        bst->print_inorder();
    }

    cout << "\n-------------\nTesting find:\n-------------" << endl;
    cout << "  ";
    bst->find(nums[0]) ? cout << "bst->find(root) good" << endl : cout << "bst->find(root) FAILED" << endl;
    cout << "  ";
    bst->find(right) ? cout << "bst->find(right) good" << endl : cout << "bst->find(right) FAILED" << endl;
    cout << "  ";
    bst->find(left) ? cout << "bst->find(left) good" << endl : cout << "bst->find(left) FAILED" << endl;
    cout << "  ";
    !bst->find(middle1) ? cout << "bst->find(middle1) good" << endl : cout << "bst->find(middle1) FAILED" << endl;
    cout << "  ";
    !bst->find(middle2) ? cout << "bst->find(middle2) good" << endl : cout << "bst->find(middle2) FAILED" << endl;
    cout << "  ";
    !bst->find(-1000000) ? cout << "bst->find(-1000000) good" << endl : cout << "bst->find(-1000000) FAILED" << endl;
    cout << "  ";
    !bst->find(1000000) ? cout << "bst->find(1000000) good" << endl : cout << "bst->find(1000000) FAILED" << endl;

    if(n < 20){
        cout << "\n-------------\nTesting print from node:\n-------------" << endl;
        cout << "  left: ";
        bst->print_from_value(left);
        cout << "  right: ";
        bst->print_from_value(right);
        cout << "  middle1: ";
        bst->print_from_value(middle1);
    }

}   

int main(){
    BST * bst = new BST();
    int test1[5] = {6,4,2,8,10};
    test(bst, test1, 5, 3, 7, 4, 8);

    BST * bst2 = new BST();
    int test2[1] = {5};
    test(bst2, test2, 1, 1, 6, 5, 5);

    BST * bst6 = new BST();
    int test6[7] = {8, 4, 2, 6, 12, 10, 14};
    test(bst6, test6, 7, 3, 9, 4, 12);

    BST * bst4 = new BST();
    int test4[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    test(bst4, test4, 10, 5, 17, 4, 18);

    BST * bst5 = new BST();
    int test5[20] = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
    test(bst5, test5, 10, 5, 17, 4, 18);

    BST * bst3 = new BST();
    int test3[500] = {160,99 ,289,894,59 ,873,430,343,443,942,603,133,624,173,922,780,879,523,465,766,940,441,19 ,319,815,193,617,399,473,718,381,558,425,870,320,6  ,418,272,639,649,142,405,423,263,131,506,769,226,352,275,801,95 ,78 ,305,770,24 ,181,326,551,195,85 ,703,938,635,626,210,833,159,46 ,662,971,947,44 ,344,227,474,927,846,439,413,564,696,446,754,742,174,287,983,74 ,485,83 ,113,698,7  ,739,748,590,917,811,52 ,830,309,175,969,513,361,589,339,685,457,965,672,908,143,205,544,198,448,536,204,682,298,640,317,188,155,336,476,422,81 ,934,876,928,888,445,147,897,459,891,135,449,699,932,731,294,967,883,845,70 ,111,889,391,92 ,664,329,653,265,562,241,863,186,494,122,106,610,102,567,86 ,152,534,223,127,884,121,62 ,852,420,968,253,358,64 ,868,832,91 ,550,270,208,22 ,43 ,849,890,618,798,840,507,471,244,466,537,641,187,828,532,631,375,301,829,482,571,136,437,673,591,668,23 ,719,370,776,54 ,236,372,630,296,963,814,771,214,120,150,749,11 ,952,924,285,999,991,100,498,786,774,914,866,5  ,469,51 ,80 ,933,283,836,954,157,438,644,994,899,280,321,642,515,524,704,333,791,643,540,847,602,447,179,981,622,346,826,212,587,389,987,601,593,973,874,921,799,744,282,87 ,202,480,646,759,768,347,48 ,978,386,597,114,232,31 ,340,725,578,605,755,189,75 ,427,15 ,456,619,800,414,324,248,28 ,421,410,881,182,315,450,582,683,666,688,574,936,166,72 ,123,600,481,842,896,314,834,273,805,238,628,230,988,660,191,509,328,611,706,221,108,743,14 ,483,177,788,747,363,499,217,604,463,665,366,412,677,404,116,949,579,629,783,594,560,194,325,458,254,274,939,432,35 ,606,670,552,58 ,61 ,522,517,976,751,342,291,129,910,47 ,878,132,84 ,511,570,674,930,576,331,178,235,313,259,713,444,332,267,433,306,946,588,761,962,838,207,848,88 ,837,496,2  ,821,491,636,985,117,669,468,408,383,365,907,995,138,50 ,948,839,997,945,941,350,455,118,861,103,931,764,816,860,549,367,778,726,520,392,925,835,153,818,647,577,154,354,850,164,409,512,929,302,401,190,293,996,406,538,757,695,982,689,56 ,545,702,218,869,904,156,554,916,55 ,364,547,528,569,599,279,741};
    test(bst3, test3, 500, 148, 705, 289, 916);
}