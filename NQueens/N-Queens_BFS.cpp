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

/*  此方法来自于github/cshaxu， 这里只是对此方法的解释

    小记： 第一次读题目没有去了解国际象棋的规则，竟不知道皇后QUEENu（Q）还能够斜线作案，所以以为只要在每一行每一列不出现两个皇后就可以了，如下面所示
    . Q . .
    Q . . .
    . . . Q
    . . Q .  假如规则真的是这样的话，那很好办。用一个Vector<int> v记录下n个值，每个值表示某行的列数。例如v[0]表示第0行的Q所在的列数，
    这样的话，上图可以表示为v={1,0,3,2};第0行的Q在第1列（行列都丛0开始）上，即（0，v【0】）。这样一来，每行必须有不同的列的值，否则Q就会在相同的行或者列上了。
    题目可以转换为排列为题，n为4的时候，四个不同的数有几种排列方法。 {0,1,2,3}{0,1,3,2}{0,2,1,3}{0,2,3,1}{0,3,1,2}{0,3,2,1} .......

    想了好几个小时候之后，发现规则不对。因为Q可以走斜线~好吧。只能重新开始想。但是仍然可以用vector 来保存答案。比如下图所示的这种情况可以表示为v = {1,3,0,2}
    . Q . .
    . . . Q
    Q . . .
    . . Q .
    如果给任何一个数组，都能转换表示成上图的形式，那么剩下的问题就变成如何去找这个数组了。





*/



bool isValid(vector<int> &table, int row, int col)
{
    for (int i = 0;i < row;++i) {
        if (table[i] == col) return false;
        if (std::abs(row - i) == std::abs(col - table[i])) return false;
    }
    return true;
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string>> result;  // 存放答案的容器
    queue<pair<vector<int>, int>> q; // 队列用来进行BFS中存放节点
    q.push(pair<vector<int>, int>(vector<int>(), 0)); // 初始化
    while (!q.empty()) {
        pair<vector<int>, int>& sub = q.front(); // sub是一个pair，first是用来存放答案的容器，second是一个int数用来表示接下来要遍历的行；
        // 如果sub.second == n，说明已经遍历完了所有行了，因为是从0行开始的
        if (sub.second == n) {
            vector<string> sol(n, string(n, '.')); // sol用来把容器里面的数转换成'Q'与'.'
            for (int i = 0;i < n;++i)
                sol[i][sub.first[i]] = 'Q';
            result.push_back(sol);
        } else {
            for (int i = 0;i < n;++i) {       // 取出sub，second表示开始的行，从第0列扫到第n-1列；
                if (isValid(sub.first, sub.second, i)) { // isValid判断能否在second行第i列，放下Q，
                    sub.first.push_back(i); // 把i存到first里面，
                    sub.second++;          // 行数加 1 ， 要把下一行的行数跟rec一起保存到队列里
                    q.push(sub);      // sub保存到队列
                    sub.first.pop_back(); // 丢掉sub里刚存的i，尝试其他列i是否也可以存放Q
                    sub.second--; // 行数还原成本行的行数
                }
            }
        }
        q.pop();
    }
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

