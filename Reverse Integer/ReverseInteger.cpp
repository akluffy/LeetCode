/*******************************************

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding.
Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be?
ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow?
Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good,
but what if throwing an exception is not an option?
You would then have to re-design the function (ie, add an extra parameter).

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

int reverse(int x) {
    if(x > INT_MAX || x < INT_MIN) throw;
    int sign;
    int result = 0, digit = 0;

    while(x != 0) {
        digit = x % 10;
        result = digit + result * 10;
        x /= 10;
    }

    return result;
}

int main()
{

    int a = 12345;
    int b = -637849;
    cout << reverse(a) << endl;
    cout << reverse(b) << endl;

    return 0;
}

