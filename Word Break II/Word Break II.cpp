/*******************************************

Word Break II

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

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

bool isvalid(string word, unordered_set<string> &dict) {
    return dict.find(word) != dict.end();
}

void helper(string &s, unordered_set<string> &dict, vector<string> &result, string cur, int end, vector<bool> &table)
{
    string temp;
    if (!table[end]) return;
    for (int i = end - 1;i >= 0;--i) {
        if (!table[i] || !isvalid(s.substr(i, end - i), dict)) continue;
        if (end == s.length()) temp = s.substr(i, end - i);
        else temp = s.substr(i, end - i) + string(" ") + cur;
        if (i == 0) result.push_back(temp);
        else helper(s, dict, result, temp, i, table);
    }
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> result;
    vector<bool> table(s.length() + 1, false);
    table[0] = true;
    for (int i = 1; i <= s.length();++i) {
        for (int j = 0;j < i;++j) {
            if (table[j] && isvalid(s.substr(j, i - j), dict)) {
                table[i] = true;
                break;
            }
        }
    }
    helper(s, dict, result, string(), s.length(), table);
    return result;
}


int main()
{
    unordered_set<string> dict  = {"cat", "cats", "and", "sand", "dog"};
    string s = "catsanddog";
    vector<string> result;
    result = wordBreak(s, dict);
    for(string &i : result) cout << i << endl;


    return 0;
}

