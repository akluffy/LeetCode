/*******************************************

There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

There are many ways to do it and I just pick the easiest one.
The algorithm is simple: Considering merge two arrays into one, and then
find the middle element (or the two middle elements) which is the median.
Actually, we don't have to merge the arrays. We can just create two indexs
to count m+n/2 times according to the sorted array order.

Example: A={1, 3, 5, 7, 9}, B={2, 4, 6, 8}, there are 9 elements in total,
so we just need find the 5th big number among two arrays. The first number
is A[0], index1++, second # is B[0], index2++, third # is A[1], index1++,
fourth # is B[2], index2++. Finally, after 5 times ++ of both indexs, the
index1 refer to A[5], so A[5] is the median.

********************************************/

#include <iostream>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int indexCount1 = 0, indexCount2 = 0;
        int median1 = -1, median2 = -1;
        for(int i = 0; i <= (m+n)/2; i++) {
            median1 = median2;
            if(indexCount2 == n || (indexCount1 < m && A[indexCount1] <= B[indexCount2]))
                median2 = A[indexCount1++];
            else median2 = B[indexCount2++];
        }
        if((m+n)%2) return (double)median2;
        else return (median1 + median2)/2.0;
}

int main() {
    int ary1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int ary2[] = {20, 30, 40, 50, 60};
    int size1 = sizeof(ary1)/sizeof(ary1[0]);
    int size2 = sizeof(ary2)/sizeof(ary2[0]);

    cout << "the median of ary1 and ary2 is : " << findMedianSortedArrays(ary1, size1, ary2, size2) << endl;


    return 0;
}
