/*******************************************

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.


子串的长度为 i，我们要求的就是长度为 i 的字串在长度为 j 的母串中出现的次数，设为 t[i][j]，若母串的最后一个字符与子串的最后一个字符不同，
则长度为 i 的子串在长度为 j 的母串中出现的次数就是母串的前 j - 1 个字符中子串出现的次数，即 t[i][j] = t[i][j - 1]，
若母串的最后一个字符与子串的最后一个字符相同，那么除了前 j - 1 个字符出现字串的次数外，还要加上子串的前 i - 1 个字符在母串的前 j - 1 个字符中出现的次数，
即 t[i][j] = t[i][j - 1] + t[i - 1][j - 1]

          a a b b c c
        1 1 1 1 1 1 1
      a 0 1 2 2 2 2 2         遇到相同的加上 前一行的前一列，否则跟这一行的前一列保持一致
      b 0 0 0 2 4 4 4
      c 0 0 0 0 0 4 8


**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int numDistinct(string S, string T) {
    int size_S = S.size();
    int size_T = T.size();
    int D[size_T+1][size_S+1];
    for(int i = 0; i < size_T + 1; i++) D[i][0] = 0;
    for(int j = 0; j < size_S + 1; j++) D[0][j] = 1;

    for(int i = 0; i < size_T; i++) {
        for(int j = 0; j < size_S; j++) {
            if(T[i] == S[j]) D[i+1][j+1] = D[i+1][j] + D[i][j];
            else D[i+1][j+1] = D[i+1][j];
        }
    }

    return D[size_T][size_S];
}

int main()
{

    cout << numDistinct("aabbccdd", "abcd");

    return 0;
}

