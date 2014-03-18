/*******************************************

Given a string containing just the characters
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order,
"()" and "()[]{}" are all valid but "(]" and "([)]" are not.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        switch(s[i]) {
        case '(':
        case '[':
        case '{':
            st.push(s[i]);
            break;
        case ')':
            if(!st.empty() && st.top() == '(') st.pop();
            else return false;
            break;
        case ']':
            if(!st.empty() && st.top() == '[') st.pop();
            else return false;
            break;
        case '}':
            if(!st.empty() && st.top() == '{') st.pop();
            else return false;
            break;
        }
    }

    return st.empty();
}

int main()
{

    string a = "((()))()(){{}}[][]";
    cout << isValid(a) << endl;


    return 0;
}

