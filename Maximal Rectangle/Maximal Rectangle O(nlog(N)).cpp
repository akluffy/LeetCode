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

int largestRectangleArea(vector<char> &height) {
    if(height.size() == 0) return 0;
    stack<int> s;
    int maxArea = 0;
    int top;
    int currArea;

    int i = 0;
    while(i < height.size()) {
        if(s.empty() || height[s.top()] < height[i])
            s.push(i++);
        else {
            top = s.top();
            s.pop();
            currArea = height[top] * (s.empty() ? i : i - s.top() - 1);
            if(maxArea < currArea) maxArea = currArea;
        }
    }
    while(!s.empty()) {
        top = s.top();
        s.pop();
        currArea = height[top] * (s.empty() ? i : i - s.top() - 1);
        if(maxArea < currArea) maxArea = currArea;
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
            matrix[i][j] = matrix[i][j] - '0'; // 先改造原先的matrix
            if(i && matrix[i][j] == 1) matrix[i][j] += matrix[i-1][j];
        }
        result = std::max(result, largestRectangleArea(matrix[i]));
    }
    return result;
}

/*********
 改造matrix举例：
  0 1 0 1 0 1               0 1 0 1 0 1
  0 0 0 1 1 1               0 0 0 2 1 2
  0 0 1 1 1 1  →→→→→→→→→→   0 0 1 3 2 3      // 注意，这里的数字不是int类型，而是表示char的ASCII码。实际显示的画面是char而不是ascii的数字
  0 0 0 1 1 1               0 0 0 4 3 4
  0 1 1 0 0 0               0 1 1 0 0 0

**********/
int main()
{
    vector<vector<char> > M = {{'1','1','1','1','1'},
                               {'0','1','1','1','0'},
                               {'1','1','0','1','1'},
                               {'1','0','1','1','1'} };


    cout << "Maximal rectangle in matrix :  " << maximalRectangle(M) << endl;

    return 0;
}

