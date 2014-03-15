/*******************************************

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false

Reference:
[1]http://blog.csdn.net/kenden23/article/details/17123497
[2]http://discuss.leetcode.com/questions/222/wildcard-matching

**********************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

bool isMatch(const char*s, const char *p) {
    if(!s && !p) return true;

    const char *star_p = NULL, *star_s = NULL;

    while(*s) {
        if(*p == '?' || *p == *s) {
            p++;
            s++;
        } else if(*p == '*') {
            // skip all continuous '*'
            while(*p == '*') p++;

            if(!*p) return true; // if end with '*', its match

            star_p = p; // store '*' position for string and pattern
            star_s = s; //
        } else if((!*p || *p != *s) && star_p) {
            s = star_s++; // skip non-match char of string, regard it matched in '*'
            p = star_p; // pattern backtrace to later char of '*'
        } else return false;
    }
    // check if later part of p are all '*'
    while(*p) {
        if(*p != '*') return false;
        p++;
    }

    return true;
}

int main()
{
    char s1[] = " ccabfasfdfd";
    char s2[] = " ca*d";

    cout << isMatch(s1, s2);


    return 0;
}

