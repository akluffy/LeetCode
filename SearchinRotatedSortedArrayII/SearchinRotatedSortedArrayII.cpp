/*******************************************

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

Follow up for "Search in Rotated Sorted Array":

What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

********************************************/

#include <iostream>

using namespace std;

bool rotatedBinarySearch(int A[], int n, int target) {
        int leftIndex = 0;
        int rightIndex = n - 1;

        while(leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex)/2;
            if(A[middleIndex] == target)  return true;

            //the left half is sorted
            if(A[leftIndex] < A[middleIndex]) {
                if(A[leftIndex] <= target && target < A[middleIndex])
                    rightIndex = middleIndex - 1;
                else
                    leftIndex = middleIndex + 1;
            }
            //the right half is sorted
            else if(A[leftIndex] > A[middleIndex]) {
                if(A[middleIndex] < target && target <= A[rightIndex])
                    leftIndex = middleIndex + 1;
                else
                    rightIndex = middleIndex - 1;
            }
            else leftIndex++;
        }

        return false;
}

int main()
{
    int ary1[] = {5, 5, 7, 8, 9, 2, 3, 3, 3, 3, 4, 4};
    int numberOfElement = sizeof(ary1)/sizeof(ary1[0]);
    cout << "The length of ary1 is :" << numberOfElement << endl;

    int key = 2;
    cout << "The index of key is : " << rotatedBinarySearch(ary1, numberOfElement, key) << endl;

    int key2 = 0;
    cout << "The index of key is : " << rotatedBinarySearch(ary1, numberOfElement, key2) << endl;

    int key3 = 4;
    cout << "The index of key is : " << rotatedBinarySearch(ary1, numberOfElement, key3) << endl;


    return 0;
}
