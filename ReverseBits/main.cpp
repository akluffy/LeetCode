/*******************************************


Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer


**********************************************/

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

using namespace std;

/*
    Say, we have a binary number X which has 8 bits
    idea:   1 2 3 4 5 6 7 8
            5 6 7 8 1 2 3 4
            7 8 5 6 3 4 1 2
            8 7 6 5 4 3 2 1
    So, how to get second line from first line?
            1 2 3 4 5 6 7 8 >> 4, and we get 0 0 0 0 1 2 3 4
            1 2 3 4 5 6 7 8 << 4, and we get 5 6 7 8 0 0 0 0
                        just use & operation 5 6 7 8 1 2 3 4
    Then, how to get third line from second line?
            5 6 7 8 1 2 3 4            5 6 7 8 1 2 3 4
          & 1 1 0 0 1 1 0 0          & 0 0 1 1 0 0 1 1
          = 5 6 0 0 1 2 0 0          = 0 0 7 8 0 0 3 4
            5 6 0 0 1 2 0 0 >> 2, and we get 0 0 5 6 0 0 1 2
            0 0 7 8 0 0 3 4 << 2, and we get 7 8 0 0 3 4 0 0
                                           |=7 8 5 6 3 4 1 2
    Follow this idea, we will get the answer.

*/

uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);  // 前16位跟后16位对换 1 2 3 4 5 6 7 8 ->  5 6 7 8 1 2 3 4
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);  // 8位对换 5 6 7 8 1 2 3 4 -> 7 8 5 6 3 4 1 2
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);  // 4位对换 7 8 5 6 3 4 1 2 -> 8 7 6 5 4 3 2 1
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);  // 2位对换 c为1100 3为0011
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);  // 1位对换 a位1010 5位0101
    return n;
}

int main()
{

    cout << reverseBits(43261596);



    return 0;
}
