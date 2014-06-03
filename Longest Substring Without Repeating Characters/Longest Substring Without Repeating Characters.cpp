/*******************************************

Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int letters[256];
    if(s.size() == 0) return 0;
    memset(letters, -1, sizeof(letters));
    int start = 0;
    int maxLength = 0;
    for(int i = 0; i < s.size(); i++) {
        int index = s[i]; //转化成为ascii码
        if(letters[index] >= 0) {
            if(maxLength < i - start) maxLength = i - start;
            i = letters[index];
            start = i + 1;
            memset(letters, -1, sizeof(letters));
            continue;
        }
        letters[index] = i;
    }
    maxLength = std::max(maxLength, int(s.size() - start));
    return maxLength;
}

int main()
{


    cout << lengthOfLongestSubstring("abcdefgabcdefghuj");

    return 0;
}

