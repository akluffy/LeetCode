/*******************************************

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

**********************************************/

#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;



    int romanToInt(string s) {
        int i = 0, result = 0, size = s.length();
        while(i < size) {
            switch(s[i]) {
                case 'M': result += 1000; break;
                case 'D': result += 500; break;
                case 'L': result += 50; break;
                case 'V': result += 5; break;
                case 'C':
                    if(i + 1 < size && (s[i+1] == 'D' || s[i+1] == 'M'))
                        result -= 100;
                    else result += 100;
                    break;
                case 'X':
                    if(i + 1 < size && (s[i+1] == 'L' || s[i+1] == 'C'))
                        result -= 10;
                    else result += 10;
                    break;
                case 'I':
                    if(i + 1 < size && (s[i+1] == 'V' || s[i+1] == 'X'))
                        result -= 1;
                    else result += 1;
                    break;
            }
            i++;
        }

    return result;
    }


int main()
{
    string str1 = "XVIII";
    string str2 = "CXCIX";
    string str3 = "MMMCCCXXXIII";
    string str4 = "MDCCCLXXX";
    string str5 = "MMMCMXCIX";

    cout << str1 << " : " << romanToInt(str1) << endl;
    cout << str2 << " : " << romanToInt(str2) << endl;
    cout << str3 << " : " << romanToInt(str3) << endl;
    cout << str4 << " : " << romanToInt(str4) << endl;
    cout << str4 << " : " << romanToInt(str5) << endl;


    return 0;
}

