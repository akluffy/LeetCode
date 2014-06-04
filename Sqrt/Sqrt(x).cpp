/*******************************************

Implement int sqrt(int x).

Compute and return the square root of x.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int sqrt(int x) {
    if(x <= 1) return x;
    double val = x;
    double last;
    do {
        last = val;
        val = (val + x/val) / 2;
    } while(abs(val - last) > 0.00000001);

    return floor(val); // Rounds x downward, returning the largest integral value that is not greater than x.
}


int main()
{

    cout << sqrt(25) << endl;

    return 0;
}

