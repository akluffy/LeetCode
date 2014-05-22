/*******************************************

Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

int minPathSum(vector<vector<int> > &grid) {
    if(grid.size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int> > Min(m, vector<int>(n, 0) );
    //int Min[m][n];
    Min[0][0] = grid[0][0];
    for(int i = 1; i < m; i++) {
        Min[i][0] = Min[i-1][0] + grid[i][0];
    }
    for(int i = 1; i < n; i++) {
        Min[0][i] = Min[0][i-1] + grid[0][i];
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            Min[i][j] = grid[i][j] + (Min[i-1][j] < Min[i][j-1] ? Min[i-1][j] : Min[i][j-1]);
        }
    }
    return Min[m-1][n-1];
}



int main()
{
    vector<vector<int> > vec = {{1,2,5}, {3,2,1}};

    cout << minPathSum(vec) << endl;

    return 0;
}

