/*******************************************

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

void generatePermute(vector<int> &num, int depth, vector<int> &visited, vector<int> &solution, vector<vector<int> > &coll);

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > coll;
    vector<int> solution;
    if(num.size() == 0) return coll;
    vector<int> visited(num.size(), 0);
    generatePermute(num, 0, visited, solution, coll);
    return coll;
}

void generatePermute(vector<int> &num, int depth, vector<int> &visited, vector<int> &solution, vector<vector<int> > &coll)     {
    if(depth == num.size()) {
        coll.push_back(solution);
        return;
    }

    for(int i = 0; i < num.size(); i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            solution.push_back(num[i]);
            generatePermute(num, depth + 1, visited, solution, coll);
            solution.pop_back();
            visited[i] = 0;
        }
    }
}



int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<vector<int> > result = permute(vec);

    for (vector<int> &v : result ) {
       for (int x : v ) std::cout << x << ' ';
       std::cout << std::endl;
    }

    return 0;
}

