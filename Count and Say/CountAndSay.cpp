/*******************************************

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

// 有一个疑问，在这个序列里面，永远不会出现4. 为什么呢？

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>


using namespace std;

    string next(string s) {
        string result;
        char key = s[0];
        int freq = 1, i = 1;
        while(i < s.length()) {
            if(key != s[i]) {
                result.push_back(freq + '0');
                result.push_back(key);
                key = s[i];
                freq = 1;
            } else {
                freq++;
            }
            i++;
        }
        result.push_back(freq + '0');
        result.push_back(key);

        return result;
    }

    string countAndSay(int n) {
        string result(1, '1');
        for(int i = 1; i < n; i++) {
            result = next(result);
        }
        return result;
    }

int main()
{
    for(int i = 1; i < 25; i++) {
        cout << countAndSay(i) << endl;
    }


    return 0;
}

