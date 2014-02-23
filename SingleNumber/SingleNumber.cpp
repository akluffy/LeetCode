/*******************************************

Single Number Total Accepted: 12254 Total Submissions: 27142 My Submissions
Given an array of integers, every element appears twice except for one.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?

********************************************/

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(int A[], int n) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        result ^= A[i];
    }

    return result;
}




int main() {

    int a[9] = {1, 2, 3, 4, 5, 1, 2, 3, 4};

    cout << singleNumber(a, 9);

    return 0;
}
