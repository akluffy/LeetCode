/*******************************************

Divide two integers without using multiplication, division and mod operator.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>




using namespace std;

    int divide(int dividend, int divisor) {
        int sign = 1;
        if(dividend < 0) sign = -sign;
        if(divisor < 0) sign = -sign;

        unsigned long long dd = abs(dividend);
        unsigned long long ds = abs(divisor);
        unsigned long c = 1;

        while(dd > ds) {
            ds <<= 1;
            c <<= 1;
        }

        int result = 0;
        while(dd >= abs(divisor)) {
            while(dd >= ds) {
                dd -= ds;
                result += c;
            }
            ds >>= 1;
            c >>= 1;
        }

        return result * sign;
    }


int main()
{

    cout << divide(100, 5) << endl;

    return 0;
}

