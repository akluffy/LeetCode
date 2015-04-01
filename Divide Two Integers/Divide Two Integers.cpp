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

        unsigned long long dd = llabs(dividend);
        unsigned long long ds = llabs(divisor);
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


    int divide2(int dividend, int divisor) {
    if(divisor == 1) return dividend;
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

    long long a =  llabs(dividend), b = llabs(divisor);
    long sign = (divisor > 0) ^ (dividend > 0) ? -1 : 1;
    int result = 0;
    int i = 0;
    while(a >= b) {
        i = 0;
        while(a >= (b << i)) {
            a -= (b << i);
            result += (1 << i);
            i++;
        }
    }


    return (result * sign);
}


int main()
{

    cout << divide(100, 5) << endl;

    return 0;
}

