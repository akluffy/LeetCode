/*******************************************

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;


int jump(int A[], int n) {

    int start = 0;
    int end = 0;
    int count = 0;
    if(n == 1) return 0;
    while(end < n) {
        int max = 0;
        count++;
        cout << "count ++ " << endl;
        for(int i = start; i <= end; i++) {
            if(A[i] + i >= n - 1) {
                cout << A[i] + i << " " << endl;
                return count;
            }
            if(A[i] + i > max)
                max = A[i] + i; cout << "max : " << max << endl;
        }
            start = end + 1;
            end = max;
            cout << "end: " <<end << endl;

    }
    cout << "count ++ " << endl;
    return count;
}




int main()
{
    int a[3] = {1,2,3};

    cout << jump(a, 3);


    return 0;
}

