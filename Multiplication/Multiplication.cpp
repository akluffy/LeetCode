/*********************

Implement multiplication by bit manipulation

**********************/


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <map>
#include <climits>
#include <assert.h>
#include <iterator>
#include <unordered_map>
#include <set>

using namespace std;


int multiplation(int a, int b) {
    if(a == 0 || b == 0) return 0;
    int sign = 1;
    if((a > 0) ^ (b > 0)) sign = -1;
    int a1 = abs(a), b1 = abs(b);
    if(b1 > a1) return sign * multiplation(b1, a1);
    int result = 0;
    while(b1 > 0) {
        int i = 1, n = 0;
        while(b1 >= (i << n)) {
            b1 -= i << n;
            result += a1 << n;
            n++;
        }
        n = 0;
    }

    return sign * result;
}



int main() {


    cout << multiplation(8, -17)  << 8 * (-17) << endl;
    cout << multiplation(100, 71)  << 100 * (71) << endl;
    return 0;
}
