/*******************************************

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

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

bool wordBreak(string s, unordered_set<string> &dict) {
    string s2 = '#' + s;
    int length = s2.size();
    vector<bool> valid(length, 0);

    valid[0] = true;
    for(int i = 1; i < length; i++) {
        for(int k = 0; k < i; k++) {
            valid[i] = valid[k] && dict.find(s2.substr(k + 1, i - k)) != dict.end();
            if(valid[i]) break;
        }
    }
    return valid[length-1];
}


int main()
{
    unordered_set<string> dict({"red", "green", "blue", "pink", "yellow"});
    string s1 = "greenblued";

    cout << wordBreak(s1, dict) << endl;

    return 0;
}

