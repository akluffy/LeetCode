/*******************************************

Given a sorted array and a target value,
return the index if the target is found. If not,
return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

    int searchInsert(int A[], int n, int target) {
        if(A[0] > target) return 0;
        else if(A[n-1] < target) return n;
        for(int i = 0; i < n; i++) {
            if(A[i] == target) return i;
            if(A[i] < target && A[i + 1] > target  ) return i + 1;
        }
    }

int main()
{

    int a[] = {1, 2, 3, 4, 5};
    cout << searchInsert(a, 5, 0) << endl;
    cout << searchInsert(a, 5, 3) << endl;
    cout << searchInsert(a, 5, 6) << endl;

    return 0;
}

