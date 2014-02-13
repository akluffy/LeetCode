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
#include <string>

using namespace std;



    string getPermutation(int n, int k) {

         string nums;
         string result;
         int levelCount = 1;

         // initialization of sequence of n.
         for(int i = 0; i < n ; i++) {
            nums.push_back(i + '1');
            levelCount = levelCount * (i+1);
         }

         // to decide the order of numbers
         k--; // because index started from 0
         for(int i = 0; i < n; i++) {
            levelCount = levelCount / (n-i); // levelCount started from (n-1)! to 1!
            int currentLeftMostIndex = k / levelCount;
            k = k % levelCount;
            result.push_back(nums[currentLeftMostIndex]);
            nums.erase(currentLeftMostIndex, 1);
         }

         return result;
    }

    /*
            int levelCount =1;
            for(int i =0; i< n; i++)
            {
                 nums[i] = i+1;
                 permCount *= (i+1);
            }
            // change K from (1,n) to (0, n-1) to accord to index
            k--;
            string targetNum;
            for(int i =0; i< n; i++)
            {
                 permCount = permCount/ (n-i);
                 int choosed = k / permCount;
                 targetNum.push_back(nums[choosed] + '0');
                 //restruct nums since one num has been picked
                 for(int j =choosed; j< n-i; j++)
                 {
                      nums[j]=nums[j+1];
                 }
                 k = k%permCount;
            }
            return targetNum;
    */





int main() {


    cout << getPermutation(4, 6);


    return 0;
}
