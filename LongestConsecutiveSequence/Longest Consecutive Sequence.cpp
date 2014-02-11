/*******************************************

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

********************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &num) {

    unordered_map<int, int> hashmap;
    int max = 0;
    // initial all hashmap's key to 1; 1 means this element has not been used.
    for(int i = 0; i < (int)num.size(); i++) hashmap[num[i]] = 1;

    for(int i = 0; i < (int)num.size(); i++) {
        if(hashmap[num[i]] == 1) {
            hashmap[num[i]] = 0;
            int len = 1;
            int leftnum = num[i] - 1;
            int rightnum = num[i] + 1;

            // only if this element does exist in the hashmap, and it's key value is 1.
            while(hashmap.count(leftnum) && hashmap[leftnum]) {
                hashmap[leftnum--] = 0; // after count, put the key to 0, so that later it will not be searched again.
                len++;
            }
            while(hashmap.count(rightnum) && hashmap[rightnum]) {
                hashmap[rightnum++] = 0; // after count, put the key to 0, so that later it will not be searched again.
                len++;
            }
            if(len > max) max = len;
        }
    }

    return max;
}

int main() {

    std::vector<int> v1 = {1, 2, 3, 9, 10, 12, 5, 6, 7, 8};

    cout << "the longest consecutive is : " << longestConsecutive(v1) << endl;


    return 0;
}
