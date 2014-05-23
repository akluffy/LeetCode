/*******************************************

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

// use an empty position in the begin of vector, adding from the end of the vecotr, then delete the empty one.
vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 2, 0);
    result[1] = 1;
    for(int i = 0; i < rowIndex; i++) {
        for(int j = rowIndex + 1; j > 0; j--) {
            result[j] += result[j-1];
        }
    }
    result.erase(result.begin());
    return result;
}



int main()
{

    for(int i = 0; i < 5; i++) {
        vector<int> r = getRow(i);
        for(int x : r)  cout << x << ' ';
        cout << endl;
    }


    return 0;
}

