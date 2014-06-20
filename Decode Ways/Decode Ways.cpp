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

int numDecodings(string s) {
    int size = s.length();
    vector<int> table(size + 1, 0);
    if (!size) return 0;
    table[0] = 1;
    table[1] = (s[0] == '0' ? 0 : 1);
    for (int i = 2;i <= size;++i) {
        switch (s[i - 2]) {
        case '1':
            switch (s[i - 1]) {
            case '0': table[i] = table[i - 2];break;
            default:  table[i] = table[i - 2] + table[i - 1];break;
            }
            break;
        case '2':
            switch (s[i - 1]) {
            case '0': table[i] = table[i - 2];break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
                table[i] = table[i - 2] + table[i - 1];break;
            default: table[i] = table[i - 1];break;
            }
            break;
        default:
            switch (s[i - 1]) {
            case '0': table[i] = 0;break;
            default:  table[i] = table[i - 1];break;
            }
            break;
        }
    }
    return table[size];
}


int main()
{
    string a = "123";
    cout << numDecodings(a) << endl;

    return 0;
}

