/*******************************************

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

/*  此方法来自于github/cshaxu，

*/



bool isValid(vector<int> &table, int row, int col)
{
    for (int i = 0;i < row;++i) {
        if (table[i] == col) return false;
        if (std::abs(row - i) == std::abs(col - table[i])) return false;
    }
    return true;
}

void helper(vector<vector<string>> &result, vector<int> sol, int rowcount, int n)
{
    if (rowcount == n) {
        vector<string> sub(n, string(n, '.'));
        for (int i = 0;i < n;++i)
            sub[i][sol[i]] = 'Q';
        result.push_back(sub);
    } else {
        for (int i = 0;i < n;++i) {
            if (isValid(sol, rowcount, i)) {
                sol.push_back(i);
                helper(result, sol, rowcount + 1, n);
                sol.pop_back();
            }
        }
    }
}



vector<vector<string> > solveNQueens(int n) {
    vector<vector<string>> result;
    vector<int> sol;
    helper(result, sol, 0, n);
    return result;
}




int main()
{
    vector<vector<string> > t = solveNQueens(6);

    for(vector<string> &i : t) {
        for(string &j : i)
            cout << j << endl;
        cout << endl;
    }


    return 0;
}

