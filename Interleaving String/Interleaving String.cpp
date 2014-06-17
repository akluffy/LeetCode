/*******************************************

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

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


bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.size();
    int len2 = s2.size();
    bool D[len1+1][len2+1];
    memset(D, 0, sizeof(D));

    if(len1 + len2 != s3.size()) return false; // s3 can be an interleaving of s1 and s2 only of sum of lengths of s1 and s2 is equal to length of s3

    for(int i = 0; i <= len1; ++i) {
        for(int j = 0; j <= len2; ++j) {
            if(i == 0 && j == 0) D[i][j] = true; // two empty strings have an empty string as interleaving
            else if(i == 0 && s2[j-1] == s3[j-1]) D[i][j] = D[i][j-1]; // if s1 is empty
            else if(j == 0 && s1[i-1] == s3[i-1]) D[i][j] = D[i-1][j]; // if s2 is empty
            else if(s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1]) D[i][j] = D[i-1][j];
            else if(s2[j-1] == s3[i+j-1] && s1[i-1] != s3[i+j-1]) D[i][j] = D[i][j-1];
            else if(s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1]) D[i][j] = (D[i-1][j] || D[i][j-1]);
        }
    }

    return D[len1][len2];
}

void test(string s1, string s2, string s3) {
    if(isInterleave(s1, s2, s3))
        cout << s3 << " is interleave of " << s1 << " and " << s2 << endl;
    else
        cout << s3 << " is Not interleave of " << s1 << " and " << s2 << endl;
}



int main()
{
    test("XXY", "XXZ", "XXZXXXY");
    test("XY" ,"WZ" ,"WZXY");
    test ("XY", "X", "XXY");
    test ("YX", "X", "XXY");
    test ("XXY", "XXZ", "XXXXZY");

    return 0;
}

