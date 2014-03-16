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

    char table[4][2] = {
        {'I', 'V'},
        {'X', 'L'},
        {'C', 'D'},
        {'M', ' '}
    };

    string intToRoman(int num) {
        int x, row = 0;
        string result;
        string sub;
        while(num) {
            sub.clear();
            x = num % 10;
            switch(x) {
                case 0:
                case 1:
                case 2:
                case 3:
                    for(int i = 0; i < x; i++) sub.push_back(table[row][0]);
                    break;
                case 4:
                    sub.push_back(table[row][0]);
                    sub.push_back(table[row][1]);
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    sub.push_back(table[row][1]);
                    for(int i = 0; i < x - 5; i++)
                    sub.push_back(table[row][0]);
                    break;
                case 9:
                    sub.push_back(table[row][0]);
                    sub.push_back(table[row + 1][0]);
                    break;
            }

            result = sub + result;
            num /= 10;
            row++;
        }

        return result;
    }



int main()
{
    int str1 = 9;
    int str2 = 59;
    int str3 = 1999;
    int str4 = 3999;

    cout << str1 << " : " << intToRoman(str1) << endl;
    cout << str2 << " : " << intToRoman(str2) << endl;
    cout << str3 << " : " << intToRoman(str3) << endl;
    cout << str4 << " : " << intToRoman(str4) << endl;


    return 0;
}

