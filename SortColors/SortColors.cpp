/*******************************************

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

void sortColors(int A[], int n) {
    int *p1 = &A[0], *p3 = &A[n-1];
    int index = 0;
    while(index < n) {
        if(A[index] == 2) {
            std::swap(*p3, A[index]);
            p3--;
            n--; // 注意，循环的上限要调整,否则会把后面所有的2，全部换到前面
            continue;
        }
        else if(A[index] == 0) {
        std::swap(*p1, A[index]);
        p1++;
        }
        index++;
    }
}



int main()
{

    int a[10] = {2, 1, 0, 2, 0, 1, 1, 0, 2, 1};
    for(int i : a) cout << i << ' ';
    cout << endl;
    sortColors(a, 10);
    for(int i : a) cout << i << ' ';
    cout << endl;

    return 0;
}

