/*******************************************

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

**********************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
    string result;
    const size_t len = a.size() > b.size() ? a.size() : b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for(size_t i = 0; i < len; i++) {
        const int ai = i < a.size() ? a[i] - '0' : 0;
        const int bi = i < b.size() ? b[i] - '0' : 0;
        const int val = (ai + bi + carry) % 2;
        carry = (ai + bi + carry) / 2;
        result.insert(result.begin(), val + '0');
    }
    if(carry == 1) {
        result.insert(result.begin(), '1');
    }

    return result;
}


int main()
{
    string s1 = "11011";
    string s2 = "001";

    cout << addBinary(s1, s2) << endl;


    return 0;
}

