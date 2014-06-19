/*******************************************

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

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

//思路请直接画图分析
string minWindow(string S, string T) {
    int s, e, rs, re;
    int Stable[256], Ttable[256];
    int Scount = 0, Tcount = T.length();
    for(int i = 0; i < 256; ++i) Stable[i] = Ttable[i] = 0;
    for(int i = 0; i < Tcount; ++i) Ttable[T[i]]++;
    s = 0; // start
    e = 0; // end
    rs = 0; // start of result
    re = S.length() - 1; // end of result, from the end of S string
    while(e < S.length()) {
        if(Ttable[S[e]] > Stable[S[e]]) Scount++;
        Stable[S[e]]++;
        if(Scount >= Tcount) {
            while(Stable[S[s]] > Ttable[S[s]]) {
                Stable[S[s]]--;
                s++;
            }
            if(e - s < re - rs) {
                re = e;
                rs = s;
            }
        }
        e++;
    }
    if(Scount >= Tcount) return S.substr(rs, re - rs + 1);
    else return string();
}



int main()
{
    string s1 = "ADBECABC";
    string s2 = "ABC";
    cout << minWindow(s1, s2) << endl;

    string s3 = "ADOBECODEBANC";
    cout << minWindow(s3, s2) << endl;


    return 0;
}

