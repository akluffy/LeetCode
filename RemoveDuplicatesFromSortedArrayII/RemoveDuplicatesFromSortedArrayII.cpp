/*******************************************
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

********************************************/

#include <iostream>

using namespace std;

int removeDuplicates(int Ary[], int n) {
    if (n < 2) return n;
    int i = 1, newLength = 1;
    bool first = true;
    while (i < n) {
        if (Ary[i-1] != Ary[i]) {
            Ary[newLength++] = Ary[i];
            first = true;
        }
        else if(first) {
            Ary[newLength++] = Ary[i];
            first = false;
        }
        i++;
    }

    return newLength;
}

int main()
{
    int ary1[] = {1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5};
    int n = sizeof(ary1)/sizeof(int);
    int newLength = removeDuplicates(ary1, n);
    cout << "The length of ary1 is :" << newLength << endl;
    for(int i = 0; i < newLength; i++) {
        cout << ary1[i] << "\t";
    }

    return 0;
}
