/*******************************************

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>


using namespace std;


int minCut(string s) {
    int size = s.length(), i, j;
    vector<vector<bool> > isParLin(size, vector<bool>(size, false)); // isParLin[i][j] == true means substring[i,j] is parlindrome
    vector<int> table(size, 0);
    if(size < 2) return 0;
    // retrieve all parlindrome substrings of s,
    for(i = size - 1; i >= 0; --i) {
        for(j = i; j < size; ++j) {
            if(i == j) isParLin[i][j] = true;
            else if(j == i + 1) isParLin[i][j] = (s[i] == s[j]);
            else isParLin[i][j] = isParLin[i+1][j-1] && (s[i] == s[j]);
        }
    }
    table[0] = 0;
    for(i = 1; i < size; ++i) {
        table[i] = 0; // if [0,i] is Parlindrome
        if(isParLin[0][i] == false) {
            table[i] = i; // i cut is the maximum cut , we will try to find smaller cut
            for(j = 0; j < i; ++j) {
                table[i] = std::min(table[i], table[j] + (isParLin[j+1][i] == true ? 1 : i - j));
            }
        }
    }
    return table[size - 1];
}


int main()
{
    string s1 = "aab";
    cout << minCut(s1) << endl;


    return 0;
}

