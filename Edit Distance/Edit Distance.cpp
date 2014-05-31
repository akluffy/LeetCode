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

int minDistance(string word1, string word2) {
    int size1 = word1.size();
    int size2 = word2.size();
    if(size1 == 0) return size2;
    if(size2 == 0) return size1;

    int D[size1+1][size2+1];
    for(int i = 0; i <= size1; i++) D[i][0] = i;
    for(int j = 0; j <= size2; j++) D[0][j] = j;
    for(int i = 1; i <= size1; i++) {
        for(int j = 1; j <= size2; j++) {
            D[i][j] = std::min(D[i-1][j] + 1, D[i][j-1] + 1);
            int x = (word1[i-1] == word2[j-1] ? 0 : 1);         // 斜方向上也是加1步~
            D[i][j] = std::min(D[i][j], D[i-1][j-1] + x);
        }
    }

    return D[size1][size2];
}

int main()
{

    cout << minDistance("12345", "steam");

    return 0;
}

