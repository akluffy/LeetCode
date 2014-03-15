/*******************************************

Write a function to find the longest common prefix
string amongst an array of strings.



**********************************************/

#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string prefix;
    if(strs.size() == 0) return prefix;
    for(int j = 0; j < strs[0].size(); j++) {
        for(int i = 1; i < strs.size(); i++) {
            if(strs[i][j] != strs[0][j]) return prefix;
        }
        prefix.push_back(strs[0][j]);
    }

    return prefix;
}

int main()
{
    string str1 = "abcdefghijk12345";
    string str2 = "abcdefghijk012345";
    string str3 = "abcdefghijk123456";
    vector<string> vec = {str1, str2, str3};

    string result = longestCommonPrefix(vec);
    cout << result;


    return 0;
}

