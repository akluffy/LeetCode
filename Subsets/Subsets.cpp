/*******************************************

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;


void helper(vector<int> sol, vector<vector<int> > &result, int start, int length, vector<int> config) {
    for(int i = start; i < length; i++) {
        config.push_back(sol[i]);
        result.push_back(config);
        start = i;
        helper(sol, result, start + 1, length, config);
        config.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    sort(S.begin(), S.end());

    result.push_back(vector<int>());
    vector<int> config;
    int n = S.size();
    helper(S, result, 0, n, config);
    return result;
}



int main()
{
    vector<int> v = {1,2,3,4};
    vector<vector<int> > t = subsets(v);

    for(vector<int> &i : t) {
        for(int &j : i)
            cout << j << ' ';
        cout << endl;
    }



    return 0;
}

