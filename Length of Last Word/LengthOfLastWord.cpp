/*******************************************

Given a string s consists of upper/lower-case alphabets
and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence
consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <map>


using namespace std;

    int lengthOfLastWord(const char *s) {
        if(s == NULL) return 0;
        const char *head = s, *tail = s;
        int cnt = 0;
        while(*s != '\0') {
            while(*s == ' ') s++;
            if(*s != '\0') {
                head = s;
                while(*s != ' ' && *s != '\0') s++;
                tail = s;
            };
        }
        while(head != tail) {
            cnt++;
            head++;
        }

        return cnt;
    }

int main()
{

    char a[] = "  hello  world google   ";
    char b[] = "                  ";
    cout << lengthOfLastWord(a) << endl;
    cout << lengthOfLastWord(b) << endl;

    return 0;
}

