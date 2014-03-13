/*******************************************

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases.
If you want a challenge, please do not see below and
 ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified
vaguely (ie, no given input specs). You are responsible
to gather all the input requirements up front.

**********************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int atoi(const char *str) {
    int num = 0;
    int sign = 1;
    const int len = strlen(str);
    int i = 0;

    while(str[i] == ' ' && i < len) i++;

    if(str[i] == '+') i++;
    if(str[i] == '-') {
        sign = -1;
        i++;
    }

    for(; i < len; i++) {
        if(str[i] < '0' || str[i] > '9') break;
        if(num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + str[i] - '0';
    }
    return num * sign;
}



int main()
{
    char a[] = "-12345";
    char b[] = "+413";
    char c[] = "++C";
    char d[] = "++123";
    char e[] = "2147483649";
    char f[] = "-2147483649";
    char g[] = "-+555";
    char h[] = "8419489FDFSD";

    cout << atoi(a) << endl;
    cout << atoi(b) << endl;
    cout << atoi(c) << endl;
    cout << atoi(d) << endl;
    cout << atoi(e) << endl;
    cout << atoi(f) << endl;
    cout << atoi(g) << endl;
    cout << atoi(h) << endl;

    return 0;
}

