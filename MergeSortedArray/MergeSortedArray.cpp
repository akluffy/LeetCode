/*******************************************

Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

Examples:

Input:  Array {1, 2, 3}
Output: A Balanced BST
     2
   /  \
  1    3

Input: Array {1, 2, 3, 4}
Output: A Balanced BST
      3
    /  \
   2    4
 /
1

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;




void merge(int A[], int m, int B[], int n) {
    if(n == 0)   return;
    else if(m == 0) {
        for(int i = 0; i < n; i++) A[i] = B[i];
    }
    else {
        int *p = &A[m-1];
        int *q = &B[n-1];
        int m1 = m, n1 = n;

        for(int i = 0; i < m + n; i++) {
            if(m1 > 0 && n1 > 0){
                if(*p >= *q) {
                    A[m+n-1 - i] = *p;
                    p--;
                    m1--;
                }
                else {
                    A[m+n-1 - i] = *q;
                    q--;
                    n1--;
                }
            }
            else if(n1 == 0) return;
            else if(m1 == 0) {
                A[m+n-1 - i] = *q;
                q--;
                n1--;
            }
        }
    }
}

int main()
{
    int a[9] = {1, 3, 5, 7, 9};
    int b[4] = {0, 2, 4, 6};
    merge(a, 5, b, 4);

    for(int i = 0; i < 9; i++) {
        cout << a[i] << "  ";
    }

    return 0;
}

