/*******************************************

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return fals

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    bool canJump(int A[], int n) {
        if(n <= 1) return true;
        if(A[0] <= 0 && n > 1) return false;
        int maxJumpLength[n];
        maxJumpLength[0] = A[0];
        for(int i = 1; i < n; i++) {
            maxJumpLength[i] = max(maxJumpLength[i-1], A[i-1]) - 1;
            if(maxJumpLength[i] < 0) return false;
        }

        return true;
    }
};



int main()
{



    return 0;
}

