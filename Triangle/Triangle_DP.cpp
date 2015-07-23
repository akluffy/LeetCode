/*******************************************

Given a certain range, produce all numbers in that range that fit the criteria.
The criteria: a number that starts with 2 of the same number, and the sum of the previous 2 is that of the next number.
Examples: 112358, 121224, 448


**********************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <map>
#include <climits>
#include <assert.h>
#include <iterator>
#include <unordered_map>

using namespace std;

    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        vector<int> result(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; --i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                cout << triangle[i][j] << " + " << result[j] << " or " << result[j+1] << endl;
                result[j] = triangle[i][j] + min(result[j] , result[j+1]);
                cout << result[j] << endl;
            }
        }

        return result[0];
    }


int main(){


    vector<vector<int> > T;
    vector<int> row1 = {-1};
    vector<int> row2 = {2, 3};
    vector<int> row3 = {1, -3, -1};
    T.push_back(row1);
    T.push_back(row2);
    T.push_back(row3);
    cout << minimumTotal(T) << endl;

    return 0;
}
