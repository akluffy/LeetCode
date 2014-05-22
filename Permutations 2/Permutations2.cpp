/*******************************************

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

void generatePermute(vector<int> &num, int depth, vector<int> &visited, vector<int> &solution, vector<vector<int> > &coll);

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > coll;
    vector<int> solution;
    if(num.size() == 0) return coll;
    vector<int> visited(num.size(), 0);
    sort(num.begin(), num.end()); // 把重复的元素连续放在一起
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
            if(i > 0 && num[i] == num[i-1] && visited[i-1] == 0) continue; //排除重复的排列
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
    vector<int> vec = {0, 1, 2, 3, 4, 1, 1};
    vector<vector<int> > result = permuteUnique(vec);

    for (vector<int> &v : result ) {
       for (int x : v ) std::cout << x << ' ';
       std::cout << std::endl;
    }

    return 0;
}

