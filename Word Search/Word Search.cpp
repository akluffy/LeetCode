/*******************************************

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_set>



using namespace std;

bool helper(vector<vector<char>> &board, int i, int j, string &word, int id)
{
    char c;
    if (word[id] != board[i][j]) return false;
    if (id == word.length() - 1) return true;
    c = board[i][j];
    board[i][j] = '.';
    if (i && helper(board, i - 1, j, word, id + 1)) return true;
    if (j && helper(board, i, j - 1, word, id + 1)) return true;
    if (i < board.size() - 1 && helper(board, i + 1, j, word, id + 1)) return true;
    if (j < board[i].size() - 1 && helper(board, i, j + 1, word, id + 1)) return true;
    board[i][j] = c;
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    for (int i = 0;i < board.size();++i) {
        for (int j = 0;j < board[i].size();++j) {
            if (helper(board, i, j, word, 0)) return true;
        }
    }
    return false;
}



int main()
{
    vector<vector<char> > B = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    cout << exist(B, "ASFD") << endl;
    cout << exist(B, "ASFDCC") << endl;

    return 0;
}

