/*******************************************

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    void nextPermutation(vector<int> &num) {
        // Find longest non-increasing suffix
        int i = num.size() - 1;
        while(i > 0 && num[i-1] >= num[i]) i--;
        // i is the head index of the suffix

        if(i == 0) {
            reverse(num.begin(), num.end());
            return ;
        }

        // Set the pivot as the num[i-1] and then
        // find the rightmost element that larger than the pivot
        int j = num.size() - 1;
        while(num[j] <= num[i-1]) j--;

        swap(num[i-1], num[j]);

        // reverse the suffix
        j = num.size() - 1;
        while(i < j) {
                swap(num[i], num[j]);
                i++;
                j--;
        }
    }



int main() {

    vector<int> v1 = {1, 2, 3, 4, 5, 1, 2};
    for(vector<int>::iterator iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
        cout << *iter1 << "\t";
    }

    nextPermutation(v1);
    cout << endl;

    for(vector<int>::iterator iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
        cout << *iter1 << "\t";
    }



    return 0;
}
