/*******************************************

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > m;
    if(numRows == 0) return m;
    vector<vector<int> > result(1, vector<int>(1,1));
    if(numRows == 1) return result;
    if(numRows == 2) {
        vector<int> row = {1,1};
        result.push_back(row);
        return result;
    }
    if(numRows > 2) {
        result.push_back(vector<int>(2,1));
        for(int i = 1; i < numRows - 1; i++){
            vector<int> row(i+2, 1);
            for(int j = 1; j < i + 1; j++) {
                row[j] = result[i][j-1] + result[i][j];
            }
            result.push_back(row);
        }
    }
    return result;
}



int main()
{



    return 0;
}

