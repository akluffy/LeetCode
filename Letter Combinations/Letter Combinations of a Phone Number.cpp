/*******************************************

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

void helper(string trans[], string &digits, unsigned deep, string &combin, vector<string> &result) {
    if(deep == digits.size()) {
        result.push_back(combin);
        return;
    }
    int curDig = digits[deep] - '0';
    for(unsigned i = 0; i < trans[curDig].size(); i++) {
        combin.push_back(trans[curDig][i]);
        helper(trans, digits, deep + 1, combin, result);
        combin.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    string trans[] = {"", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string seq;
    helper(trans, digits, 0, seq, result);
    return result;
}




int main()
{
    vector<string> vec = letterCombinations("123");
    for(string &i : vec) cout << i << endl;

    return 0;
}

