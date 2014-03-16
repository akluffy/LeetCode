/*******************************************

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => falses
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.

**********************************************/

#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

bool isNumber(const char *s) {
    bool num = false;
    const char *p = s;

    while(*p == ' ') p++;
    if(!*p) return false;

    if(*p == '+' || *p == '-') {
        if(!isdigit(*(p + 1)) && *(p + 1) != '.')
            return false;
        else p++;
    }

    while(isdigit(*p)) {
        num = true;
        p++;
    }

    if(*p == '.') {
        if(isdigit(*(p - 1)) || isdigit(*(p + 1)))
            p++;
        else return false;
    }

    while(isdigit(*p)) {
        num = true;
        p++;
    }

    if(*p == 'e') {
        if(!num) return false;
        if(*(p + 1) == '+' || *(p +1) == '-')
            p++;
        if(!isdigit(*(p + 1))) return false;
        else p++;
        while(isdigit(*p)) p++;
    }
    while(*p == ' ') p++;
    if(*p) return false;
    else return true;
}



int main()
{
    char str1[] = "2e+10";
    char str2[] = "2e-10";
    char str3[] = "+.1";
    char str4[] = "-2.e+99";


    cout << str1 << " : " << isNumber(str1) << endl;
    cout << str2 << " : " << isNumber(str2) << endl;
    cout << str3 << " : " << isNumber(str3) << endl;
    cout << str4 << " : " << isNumber(str4) << endl;


    return 0;
}

