/*******************************************

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.

https://oj.leetcode.com/problems/sudoku-solver/

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


bool oneUnitCheck2(vector<vector<char> > &board, int row, int col) {
    for(int k = 0; k < 9; k++) {
        if(k != col && board[row][k] == board[row][col]) return false;
        if(k != row && board[k][col] == board[row][col]) return false;
    }
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            if(i != row && j != col && board[i][j] == board[row][col]) return false;
        }
    }
    return true;
}

bool oneUnitCheck(vector<vector<char> > &board, int x, int y) {
    for(int i = 0; i < 9; i++) {
        if(i != x && board[i][y] == board[x][y] ) return false; // check the column y
        if(i != y && board[x][i] == board[x][y] ) return false; // check the row x
        int girdX, girdY;
        girdX = i % 3 + x / 3 * 3;
        girdY = i / 3 + y / 3 * 3;
        if(girdX != x && girdY != y && board[girdX][girdY] == board[x][y]) return false;
    }

    return true;
}

bool isFull(vector<vector<char> > &board, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(board[i][j] == '.') return false;
        }
    }
    return true;
}



bool helper(vector<vector<char> > &board, int row, int col) {
    if(isFull(board, 9, 9)) return true;
    if(col >= 9) return helper(board, row + 1, 0);
    if(board[row][col] == '.') {
        for(int i = 0; i < 9; i++) {
            board[row][col] = (char)(i + '1');
            if(oneUnitCheck2(board, row, col)) {
                if(helper(board, row, col + 1)) return true;
            }
            board[row][col] = '.';
        }
    } else {
        return helper(board, row, col + 1);
    }

    return false;
}

void solveSudoku(vector<vector<char> > &board) {
    helper(board, 0, 0);
}

int main()
{

vector<vector<char> > M = { {'3', '.', '6', '5', '.', '8', '4', '.', '.'},
                            {'5', '2', '.', '.', '.', '.', '.', '.', '.'},
                            {'.', '8', '7', '.', '.', '.', '.', '3', '1'},
                            {'.', '.', '3', '.', '1', '.', '.', '8', '.'},
                            {'9', '.', '.', '8', '6', '3', '.', '.', '5'},
                            {'.', '5', '.', '.', '9', '.', '6', '.', '.'},
                            {'1', '3', '.', '.', '.', '.', '2', '5', '.'},
                            {'.', '.', '.', '.', '.', '.', '.', '7', '4'},
                            {'.', '.', '5', '2', '.', '6', '3', '.', '.'}};

    solveSudoku(M);
    for(vector<char> &i : M) {
        for(char j : i) cout << j << ' ';

        cout << endl;
    }


    return 0;
}

