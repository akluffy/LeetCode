/*******************************************

Longest non-decreasing sequence

Dynamic programming

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

int longestIncreasingSequence(int A[], int n) {
    vector<int> D(n, 1); // D[i] records the length of the longest subsequence of A[0] to A[i-1];
    int len = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] <= A[i] && D[j] + 1 > D[i]) D[i] = D[j] + 1; // every j < i, if A[j] < A[i], check D[j] and D[i], D[j] + 1 > D[i], D[i] needs to update to D[j]+1
        }
        if(D[i] > len) len = D[i];
    }

    return len;
}



int main()
{

    int A[] = {5, 3, 4, 8, 7, 2, 1, 9, 6};

    cout << longestIncreasingSequence(A, 9) << endl;

    return 0;
}

