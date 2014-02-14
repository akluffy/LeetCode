/*******************************************

Given n non-negative integers representing an elevation map where the width
of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
Thanks Marcos for contributing this image!

********************************************/

#include <iostream>
#include <cstring>

using namespace std;


 int trap(int A[], int n) {
        int totalWater = 0;
        int rightH = A[n-1];
        int *leftH = new int[n];
        memset(leftH, 0, n*sizeof(int));
        int effectH;

        for(int i = 1; i < n-1; i++) {
            if(leftH[i-1] < A[i-1]) leftH[i] = A[i-1];
            else leftH[i] = leftH[i-1];
        }

        for(int j = n-2; j > 0; j--) {
            effectH = min(rightH, leftH[j]);
            if(A[j] < effectH) totalWater += (effectH - A[j]);
            if(A[j] > rightH) rightH = A[j];
        }

        return totalWater;
    }


int main() {

    int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trap(A, 12);

    return 0;
}
