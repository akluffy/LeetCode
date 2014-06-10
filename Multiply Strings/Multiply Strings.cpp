/*******************************************

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <climits>


using namespace std;

string multiply(string num1, string num2) {

    string result(num1.size() + num2.size(), '0');
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int digit1 = 0, digit2 = 0;
    for(int i = 0; i < num1.size(); i++) {
        digit1 = num1[i] - '0';
        int carry = 0;
        for(int j = 0; j < num2.size(); j++) {
            digit2 = num2[j] - '0';
            int temp = digit1 * digit2;
            int exist = result[i+j] - '0';
            result[i+j] = (temp + exist + carry) % 10 + '0';
            carry = (temp + exist + carry) / 10;
        }
        if(carry > 0) result[i+num2.size()] = carry + '0';
    }

    int i = result.size() - 1;
    while(result[i] == '0' && i > 0) {
        result.pop_back();
        i--;
    }
    reverse(result.begin(), result.end());
    return result;
}


int main()
{
    string s1 = "9";
    string s2 = "99";
    string ans = multiply(s1, s2);
    cout << ans << endl;

    return 0;
}

