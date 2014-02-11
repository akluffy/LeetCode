/*******************************************

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

********************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {

    unordered_map<int, int> hashmap;
    int n = (int)numbers.size();
    vector<int> index(2, -1);

    for(int i = 0; i < n; i++) hashmap[numbers[i]] = i;

    for(int i = 0; i < n; i++) {
        int desiredNum = target - numbers[i];
        // check if desiredNum is in the hashmap. In particular, the desiredNum cannot be the number[i] itself. For example, the target is 10, numbers[i(say i = 3)] = 5, the desiredNum is 5 that is the same as number[3], so if i(3) equals hashmap[5], it doesn't account.
        if(hashmap.count(desiredNum) && i != hashmap[desiredNum]) {
            index[0] = hashmap[numbers[i]] + 1;
            index[1] = hashmap[desiredNum] + 1;
            break;
        }
    }
        if(index[0] > index[1]) swap(index[0], index[1]);

        return index;
}



int main() {

    std::vector<int> v1 = {1, 2, 3, 22, 10, 12, 5, 6, 7, 8};
    int target = 99;
    vector<int> result = twoSum(v1, target);

    cout << "The target is : " << target << endl;
    cout << "the indices are : " << result[0] << " and " << result[1] << endl;


    return 0;
}
