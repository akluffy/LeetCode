/*******************************************

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> table(n, 0);
        if(obstacleGrid[0][0] != 1) table[0] = 1;

        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][0] != 1 && table[0] != 0) table[0] = 1;
            else table[0] = 0;
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) table[j] = 0;
                else table[j] += table[j - 1];
            }
        }

        return table[n - 1];
    }

int main()
{

    vector<vector<int> > a = {
        {0,0},
        {1,0}
    };

    cout << uniquePathsWithObstacles(a) << endl;


    return 0;
}

