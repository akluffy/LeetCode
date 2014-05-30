/*******************************************

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

思路：
  比如："abade"
  start = 0; i = start;

step1     先看a，再看b，再看C，再看d，再看e    所以“a”“b”“a”“d”“e”为一个解
          然后看看de，不是；
          再看cde，不是；
          接着看bcde，不是；
step2     看ab，不是；
step3     看aba，是的；看d，是的，看e，是的     所以"aba" "d" "e" 也是一个解
          看de不是；
step4     看abcd，不是；
step5     看abcde 不是；




**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

void helper(string &s, vector<string> &output, vector<vector<string> > &result, int start);
bool isPalindrome(string &s, int start, int end);

vector<vector<string>> partition(string s) {
    vector<vector<string> > result;
    vector<string> output;
    helper(s,output, result, 0);
    return result;
}

void helper(string &s, vector<string> &output, vector<vector<string> > &result, int start) {
    if(start == s.size()) {
        result.push_back(output);
        return;
    }

    for(int i = start; i < s.size(); i++) {
        if(isPalindrome(s, start, i)) {
            output.push_back(s.substr(start, i - start + 1));
            helper(s, output, result, i + 1);
            output.pop_back();
        }
    }
}

bool isPalindrome(string &s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int main()
{
    vector<vector<string> > vec = partition("aabb");
    for(vector<string> &i : vec) {
        for(string &j : i) cout << '"' << j << '"' << ' ';
        cout << endl;
    }

    return 0;
}

