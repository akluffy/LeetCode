/*********************

Given an integer matrix, find a submatrix where the sum of numbers is zero. Your code should return the coordinate of the left-up and right-down number.
Example
Given matrix

[
  [1 ,5 ,7],
  [3 ,7 ,-8],
  [4 ,-8 ,9],
]
return [(1,1), (2,2)]

Challenge
O(n3) time.

**********************/


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <map>
#include <climits>
#include <assert.h>
#include <iterator>
#include <unordered_map>

using namespace std;

vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
    // Write your code here
    if(matrix.empty() || matrix[0].empty()) return vector<vector<int>>(0);
    int rLen = matrix.size(), cLen = matrix[0].size();
    vector<vector<int>> result;
    for(int i = 0; i < rLen; ++i) {
        for(int j = 0; j < cLen; ++j) {
            vector<int> DP(cLen - j + 1, 0);
            for(int x = i; x < rLen; ++x) {
                int prev = DP[0], curr;
                for(int y = j; y < cLen; ++y) {
                    curr = DP[y-j+1];
                    DP[y-j+1] = DP[y-j] + DP[y-j+1] - prev + matrix[x][y];
                    cout << "i:" << i << ", j:" << j << "  |  ";
                    cout << "x:" << x << ", y:" << y << "     DP[y+1]: " << DP[y-j+1] << endl;
                    prev = curr;
                    if(DP[y-j+1] == 0) return {{i, j}, {x, y}};
                }
            }
        }
    }

    return result;
}

    vector<vector<int>> submatrixSum2(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return vector<vector<int>>(0);
        int rLen = matrix.size(), cLen = matrix[0].size();
        vector<vector<int>> result;
        for(int i = 0; i < rLen; ++i) {
            for(int j = 0; j < cLen; ++j) {
                vector<vector<int>> DP(rLen - i + 1, vector<int>(cLen - j + 1, 0));
                for(int x = i; x < rLen; ++x) {
                    for(int y = j; y < cLen; ++y) {
                        DP[x-i+1][y-j+1] = DP[x-i+1][y-j] + DP[x-i][y-j+1] - DP[x-i][y-j] + matrix[x][y];
                        cout << "i:" << i << ", j:" << j << "  |  ";
                        cout << "x:" << x << ", y:" << y << "     DP[x+1][y+1]: " << DP[x-i+1][y-j+1] << endl;
                        if(!DP[x-i+1][y-j+1]) return {{i, j}, {x, y}};
                    }
                }
            }
        }

        return result;
    }


int main() {

    vector<vector<int>> M = {{6, 3, 7, -8}, {4, -8, 9, 1}, {1,5,7,5}, {4, 2, 3, 1}};
    vector<vector<int>> M2 = {{1, 5, 7}, {3, 7, -8}, {4, -8, 9}};
    vector<vector<int>> result = submatrixSum(M);
    for(auto i : result) {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    for(auto i : M) {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }

    return 0;
}
