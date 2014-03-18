/*******************************************

Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()",
which has length = 2.

Another example is ")()())", where the longest valid
parentheses substring is "()()", which has length = 4.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    int result = 0;
    stack<int> left;
    stack<pair<int, int> > leftRight;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') left.push(i);
        else if(!left.empty()) {
            pair<int, int> sub(left.top(), i);
            left.pop();
            while(!leftRight.empty() && sub.first < leftRight.top().first)
                leftRight.pop();
            if(!leftRight.empty() && leftRight.top().second == sub.first - 1) {
                sub.first = leftRight.top().first;
                leftRight.pop();
            }
            leftRight.push(sub);
            result = max(result, sub.second + 1 - sub.first);
        }
    }

    return result;
}

int main()
{

    string a = "((()))()(){{}}[][]";
    cout << longestValidParentheses(a) << endl;

    return 0;
}

