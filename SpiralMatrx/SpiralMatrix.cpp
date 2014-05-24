/*******************************************

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

// generateBorder 函数里非递归部分将产生四条边，
void readBorder(vector<vector<int> > &matrix,
                    int rowStart, int rowLength,
                    int colStart, int colLength,
                    vector<int> &result)
{
    if(rowLength <= 0 || colLength <= 0) return;

    // 当行长度或者列长长度为1的时候直接输出最后的这行（列）然后返回
    // 在这题里，其实只需要一个判断就行了，因为长跟宽是相同的，所以rowLength必须等于colLength， 但是这个函数适用于M*N矩阵，不仅仅限于此题
    if(rowLength == 1) {
        for(int i = colStart; i < colStart + colLength; i++)
            result.push_back(matrix[rowStart][i]);
        return;
    }

    if(colLength == 1) {
        for(int i = rowStart; i < rowStart + rowLength; i++)
            result.push_back(matrix[i][colStart]);
        return;
    }

    // 产生四条边，并且递归调用 从而进入内部的四条边的计算
    for(int i = colStart; i < colStart + colLength - 1; i++)
        result.push_back(matrix[rowStart][i]);
    for(int i = rowStart; i < rowStart + rowLength - 1; i++)
        result.push_back(matrix[i][colStart+colLength-1]);
    for(int i = colStart; i < colStart + colLength - 1; i++)
        result.push_back(matrix[rowStart+rowLength-1][2*colStart+colLength-1 - i]);
    for(int i = rowStart; i < rowStart + rowLength - 1; i++)
        result.push_back(matrix[2*rowStart+rowLength-1 - i][colStart]);

    readBorder(matrix, rowStart+1, rowLength-2, colStart+1, colLength-2, result);
}

// The request function only one input n;
vector<int> spiralOrder(vector<vector<int> > &matrix) {
    if(matrix.empty()) return vector<int>();
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result;
    readBorder(matrix, 0, m, 0, n, result);
    return result;
}


int main()
{
    vector<vector<int> > vec = {{1,2,3,4,5,6,7,8,9,10}, {11,12,13,14,15,16,17,18,19,20}};
    //vector<vector<int> > vec = {};

    for(vector<int> &i : vec) {
        for(int j : i) {
            if(j < 10) cout << ' ' << j << ' ';
            else cout << j << ' ';
        }
        cout << endl;
    }

    vector<int> v = spiralOrder(vec);

    for(unsigned i = 0; i < v.size(); i++) cout << v[i] << ' ';

    return 0;
}

