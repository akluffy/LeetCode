/*******************************************

A robot is located at the top-left corner of a m x n grid
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right
corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

    int uniquePaths(int m, int n) {
        vector<int> table(n, 1);
        if (!m || !n) return 0;
        for (int i = 1;i < m;++i) {
            for (int j = 1;j < n;++j) {
                table[j] += table[j - 1];
            }
        }
        return table[n - 1];
    }

int main()
{

cout << uniquePaths(10, 10);

    return 0;
}

