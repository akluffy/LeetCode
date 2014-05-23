/*******************************************

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;



/*
    leftNum and rightNum refer to the number of remianing p
*/

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < m; i++) {
        if(target >= matrix[i][0] && target <= matrix[i][n-1]) {
            return std::find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end();
        }
    }
    return false;
}


int main()
{

    vector<vector<int> > matrix = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};

    if(searchMatrix(matrix, 17))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

