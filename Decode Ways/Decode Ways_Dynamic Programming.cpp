/*******************************************

Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>




using namespace std;

int check(char one) {
    if(one != '0') return 1;
    else return 0;
}

int check(char a, char b) {
    if(a == '1' || (a == '2' && b <= '6')) return 1;
    else return 0;
}

int numDecodings(string s) {
    if(!s.length()) return 0;
    if(s.size() == 1) return check(s[0]);
    int fn = 0, f1 = 0, f2 = (s[0] == '0' ? 0 : 1); // f2 + f1 = fn
    f1 = (check(s[0]) * check(s[1]) + check(s[0], s[1]));
    for(int i = 2; i < s.length(); ++i) {
        if(check(s[i])) fn += f1;
        if(check(s[i-1], s[i])) fn += f2;
        if(fn == 0) return 0;
        f2 = f1;
        f1 = fn;
        fn = 0;
    }

    return f1;
}


int main()
{
    string a = "023";
    cout << numDecodings(a) << endl;

    return 0;
}

