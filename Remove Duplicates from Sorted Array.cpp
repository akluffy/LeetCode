/*******************************************
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

#include <iostream>

using namespace std;
********************************************/

int removeDuplicates(int Ary[], int n) {
    if (n < 2) return n;
    int i = 1, j = 1;
    while (i < n) {
        if (Ary[i-1] != Ary[i]) Ary[j++] = Ary[i];
        i++;
    }

    return j;
}

int main()
{
    int ary1[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int newLength = removeDuplicates(ary1, 10);
    cout << "The length of ary1 is :" << newLength << endl;
    for(int i = 0; i < newLength; i++) {
        cout << ary1[i] << "\t";
    }

    return 0;
}
