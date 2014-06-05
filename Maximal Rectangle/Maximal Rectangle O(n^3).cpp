/*******************************************

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

Reference: http://www.cnblogs.com/lichen782/p/leetcode_maximal_rectangle.html

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <climits>


using namespace std;

int maxRectangle(vector<vector<char> > &matrix, int row, int col) {
    int maxArea = 0;
    int minWidth = INT_MAX;
    for(int i = row; i < matrix.size() && matrix[i][col] == '1'; i++) {
        int width = 0;
        while(col + width < matrix[row].size() && matrix[i][col+width] == '1') {
            width++;
        }
        if(width < minWidth) {
            minWidth = width;
        }
        int area = minWidth * (i - row + 1);
        if(area > maxArea) maxArea = area;
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.size() == 0) return 0;
    int result = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            result = max(result, maxRectangle(matrix, i, j));
        }
    }
    return result;
}

int main()
{
    vector<vector<char> > M = {{'1','1','1','1','1'},
                               {'0','1','1','1','0'},
                               {'1','1','0','1','1'},
                               {'1','0','1','1','1'} };

    cout << "Max Rectangle Area from (0, 0) : " << maxRectangle(M, 0, 0) << endl;
    cout << "Maximal rectangle in matrix :  " << maximalRectangle(M) << endl;

    return 0;
}

