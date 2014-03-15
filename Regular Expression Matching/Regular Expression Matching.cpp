/*******************************************

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true

Reference:
[1]http://blog.csdn.net/kenden23/article/details/16902083
[2]http://leetcode.com/2011/09/regular-expression-matching.html

**********************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

bool isMatch(const char*s, const char *p) {
    assert(s && p);
    if(*p == '\0') return *s == '\0';

    // when next char is not '*': must match current character
    if(*(p+1) != '*') {
        assert(*p != '*');
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
    }

    // when next char is '*'
    while((*p == *s) || (*p == '.' && *s != '\0')) {
        if(isMatch(s, p+2)) return true;
        s++;
    }

    return isMatch(s, p+2);
}

int main()
{
    char s1[] = "ccd";
    char s2[] = "c*d";

    cout << isMatch(s1, s2);


    return 0;
}

