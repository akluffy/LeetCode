/*******************************************

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

// generateBorder 函数里非递归部分将产生四条边，
void generateBorder(vector<vector<int> > &matrix,
                    int rowStart, int rowLength,
                    int colStart, int colLength,
                    int val)
{
    if(rowLength <= 0 && colLength <= 0) return;

    // 当行长度或者列长长度为1的时候直接输出最后的这行（列）然后返回
    // 在这题里，其实只需要一个判断就行了，因为长跟宽是相同的，所以rowLength必须等于colLength， 但是这个函数适用于M*N矩阵，不仅仅限于此题
    if(rowLength == 1) {
        for(int i = colStart; i < colStart + colLength; i++)
            matrix[rowStart][i] = val++;
        return;
    }

    if(colLength == 1) {
        for(int i = rowStart; i < rowStart + rowLength; i++)
            matrix[i][colStart] = val++;
        return;
    }

    // 产生四条边，并且递归调用 从而进入内部的四条边的计算
    for(int i = colStart; i < colStart + colLength - 1; i++)
        matrix[rowStart][i] = val++;
    for(int i = rowStart; i < rowStart + rowLength - 1; i++)
        matrix[i][colStart+colLength-1] = val++;
    for(int i = colStart; i < colStart + colLength - 1; i++)
        matrix[rowStart+rowLength-1][2*colStart+colLength-1 - i] = val++;
    for(int i = rowStart; i < rowStart + rowLength - 1; i++)
        matrix[2*rowStart+rowLength-1 - i][colStart] = val++;

    generateBorder(matrix, rowStart+1, rowLength-2, colStart+1, colLength-2, val);
}

// The request function only one input n;
vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    generateBorder(matrix, 0, n, 0, n, 1);
    return matrix;
}


int main()
{
    vector<vector<int> > vec;
    vec = generateMatrix(9);
    for(vector<int> &i : vec) {
        for(int j : i) {
            if(j < 10) cout << ' ' << j << ' ';
            else cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}

