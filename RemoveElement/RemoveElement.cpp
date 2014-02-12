/*******************************************

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


    int removeElement(int A[], int n, int elem) {
        int i = 0, j = 0;
        while(j < n) {
            if(A[j] == elem) j++;
            else A[i++] = A[j++];
        }

        return i;
    }



int main() {

    int A[] = {1, 2, 3, 4, 5, 1, 2};
    int target = 1;

    cout << "The length of array is : " << sizeof(A)/sizeof(A[0]) << endl;
    cout << "After remove of the : " << target << endl;
    cout << "The new length of array is: " << removeElement(A, sizeof(A)/sizeof(A[0]), target) << endl;


    return 0;
}
