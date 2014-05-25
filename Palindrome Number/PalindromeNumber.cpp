/*******************************************

Determine whether an integer is a palindrome. Do this without extra space.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    int copy = x;
    int s = 1;
    while(copy / 10) {
        s *= 10;
        copy /= 10;
    }

    int s1 = s;
    copy = x;
    while(s) {
        int xl = x, xr = x;
        xr = x % 10;
        xl = copy / s1;
        cout << xr << ' ' << xl << endl;
        if(xl != xr) return false;

        x /= 10;
        copy %= s1;
        s1 /= 10;
        s /= 100;
    }
    return true;
}


int main()
{


    cout << isPalindrome(123454321) << endl;

    return 0;
}

