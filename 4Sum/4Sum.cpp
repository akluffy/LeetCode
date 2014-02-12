/*******************************************

Given an array S of n integers, are there elements a, b, c,
and d in S such that a + b + c + d = target? Find all unique
quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order.
(ie, a ¡Ü b ¡Ü c ¡Ü d) The solution set must not contain duplicate quadruplets.

For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {

    int n = (int)num.size();
    vector<vector<int> > result;
    sort(begin(num), end(num));

    for(int i = 0; i < n-3; i++) {
        if(i > 0 && num[i-1] == num[i]) continue;

        for(int j = i + 1; j < n-2; j++) {
            if(j > i + 1 && num[j-1] == num[j]) continue;
            int x = j + 1, y = n - 1;
            while(x < y) {
                int sum = num[i] + num[j] + num[x] + num[y];
                if(sum < target) x++;
                else if(sum > target) y--;
                else {
                    vector<int> sub;
                    sub.push_back(num[i]);
                    sub.push_back(num[j]);
                    sub.push_back(num[x]);
                    sub.push_back(num[y]);
                    result.push_back(sub);
                    do {x++;} while(x < y && num[x-1] == num[x]);
                    do {y--;} while(x < y && num[y+1] == num[y]);
                }
            }
        }
    }

    return result;
}



int main() {

    std::vector<int> v1 = {-5, -3, -1, -1, -1, 0, 0, 0, 0, 1, 2, 3, 5, -2, -3, 6, -15, 10};

    vector<vector<int> > result1 = fourSum(v1, 5);
    for(auto iter1 : result1) {
        for(auto iter2 : iter1) {
            cout << iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}
