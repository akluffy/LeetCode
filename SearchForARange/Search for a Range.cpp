/*******************************************

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> searchRange(int A[], int n, int target) {
    vector<int> result;
    int start = 0, end = n - 1;
    int i = (start + end) / 2;
    while(A[i] != target && start <= end) {
        if(A[i] < target) start = i + 1;
        else if(A[i] > target)  end = i - 1;
        i = (start + end) / 2;
    }
    if(A[i] == target) {
        int x = i, y = i;
        while(x - 1 >= 0 && A[x-1] == target) x--;
        while(y + 1 <= end && A[y+1] == target) y++;
        result.push_back(x);
        result.push_back(y);
        return result;
    } else {
        result = vector<int>(2,-1);
        return result;
    }
}





int main()
{
    int A[5] = {1,2,3,4,5};
    int B[1] = {1};
    int C[2] = {1, 4};
    vector<int> ans = searchRange(C, 2, 4);

    for(int &i : ans) cout << i << ", ";

    return 0;
}

