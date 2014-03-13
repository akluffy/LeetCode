/*******************************************

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack,
or null if needle is not part of haystack.

**********************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char *strStr(char *haystack, char *needle) {
    if(!*needle) return haystack;
    while(*haystack != '\0') {
        if(*haystack == *needle) {
            char *result = haystack;
            char *temp1 = haystack, *temp2 = needle;
            while(*temp1 == *temp2) {
                temp1++;
                temp2++;
                if(*temp2 == '\0') return result;
            }
            if(*temp1 == '\0') return NULL;
            }
        haystack++;
    }
    return NULL;
}



int main()
{
    char a[] = "A man, a plan, a canal: Panama";
    char b[] = "plan";
    char *pch = strStr(a, b);
    strncpy(pch, "book", 4);
    puts(a);

    return 0;
}

