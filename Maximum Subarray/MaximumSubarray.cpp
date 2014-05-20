/*******************************************

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;



class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max_so_far = 0, max_ending_here = 0;
        int max = A[0];
        for(int i = 0; i < n; i++) {
            max_ending_here += A[i];
            if(max_ending_here < 0) max_ending_here = 0;
            if(max_so_far < max_ending_here) max_so_far = max_ending_here;
            if(A[i] <= 0) {
                max = max > A[i] ? max : A[i];
            }
        }
        if(max_so_far > 0) return max_so_far;
        else return max;
    }
};

int main()
{


    return 0;
}

