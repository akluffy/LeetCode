/*******************************************

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.


********************************************/

#include <iostream>

using namespace std;

int rotatedBinarySearch(int A[], int n, int target) {
        int leftIndex = 0;
        int rightIndex = n - 1;

        while(leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex)/2;
            if(A[middleIndex] == target)  return middleIndex;

            //the left half is sorted
            if(A[leftIndex] <= A[middleIndex]) {
                if(A[leftIndex] <= target && target < A[middleIndex])
                    rightIndex = middleIndex - 1;
                else
                    leftIndex = middleIndex + 1;
            }
            //the right half is sorted
            else {
                if(A[middleIndex] < target && target <= A[rightIndex])
                    leftIndex = middleIndex + 1;
                else
                    rightIndex = middleIndex - 1;
            }
        }

        return -1;
}

int main()
{
    int ary1[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int numberOfElement = sizeof(ary1)/sizeof(ary1[0]);
    cout << "The length of ary1 is :" << numberOfElement << endl;

    int key = 2;
    cout << "The index of key is : " << rotatedBinarySearch(ary1, numberOfElement, key) << endl;

    int key2 = 0;
    cout << "The index of key is : " << rotatedBinarySearch(ary1, numberOfElement, key2) << endl;


    return 0;
}
