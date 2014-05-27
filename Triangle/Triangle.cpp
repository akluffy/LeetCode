/*******************************************

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;


// From bottom to top
int minimumTotal(vector<vector<int> > &triangle) {
    int row = triangle.size();
    vector<int> Min(triangle[row-1].size(), 0);
    for(int i = row - 1; i >= 0; i--) {
        int col = triangle[i].size();
        for(int j = 0; j < col; j++) {
            if(i == row - 1) {
                Min[j] = triangle[i][j];
                continue;
            }
            Min[j] = std::min(Min[j], Min[j+1]) + triangle[i][j];
        }
    }
    return Min[0];
}




int main()
{



    return 0;
}

