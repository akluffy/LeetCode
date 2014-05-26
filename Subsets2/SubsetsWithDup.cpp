/*******************************************

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
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


void helper(vector<int> &sol, vector<vector<int> > &result, int start, vector<int> config, vector<bool> &visited) {
    for(unsigned int i = start; i < sol.size(); i++) {

        if(i > 0 && sol[i] == sol[i-1] && visited[i-1] == false) {
    //            cout << "i : " << i << " is duplicate" << endl;
                continue;
        }

        config.push_back(sol[i]);
        result.push_back(config);

    //     cout << " i :" << i << "     " << "result[i] : ";
    //     for(int i : config) cout << i << ' ';
    //     cout << endl;

        start = i;
        visited[i] = true;
        helper(sol, result, start + 1, config, visited);
        config.pop_back();
        visited[i] = false;
    }
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    sort(S.begin(), S.end());
    vector<bool> visited(S.size(), false);
    result.push_back(vector<int>());
    vector<int> config;

    helper(S, result, 0, config, visited);
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

