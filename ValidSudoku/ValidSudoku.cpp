/*******************************************

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool oneUnitCheck(vector<vector<char> > &board, int x, int y) {
    for(int i = 0; i < 9; i++) {
        if(i != x && board[i][y] == board[x][y] ) return false; // check the column y
        if(i != y && board[x][i] == board[x][y] ) return false; // check the row x
        // check the gird (3*3 units)
        int girdX, girdY;
        girdX = i % 3 + x / 3 * 3;
        girdY = i / 3 + y / 3 * 3;
        if(girdX != x && girdY != y && board[girdX][girdY] == board[x][y]) return false;
    }

    return true;
}

bool isValidSudoku(vector<vector<char> > &board) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.' && !oneUnitCheck(board, i, j)) return false;
        }
    }

    return true;
}




int main() {





    return 0;
}
