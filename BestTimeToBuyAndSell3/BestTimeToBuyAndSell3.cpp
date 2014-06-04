/*******************************************

Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int maxPofit(vector<int> &prices) {
    int result = 0;
    int n = prices.size();
    if(n == 0) return 0;

    int left[n], right[n];
    memset(left, 0, sizeof(left));
    memset(right, 0 , sizeof(right));
    int min = prices[0];
    for(int i = 1; i < n; i++) {
        left[i] = prices[i] - min > left[i-1] ? prices[i] - min : left[i-1];
        min =  prices[i] > min ? min : prices[i];
    }
    int max = prices[n-1];
    for(int i = n - 2; i >= 0; i--) {
        right[i] = max - prices[i] > right[i+1] ? max - prices[i] : right[i+1];
        max = prices[i] > max ? prices[i] : max;
    }

    for(int i = 0; i < n; i++) {
        result = left[i] + right[i] > result ? left[i] + right[i] : result;
    }

    return result;
}

int main()
{
    vector<int> prices = {0,1,2,34,5,6,7,8,0,4,1,2,4,55,15,12,20};

    cout << maxPofit(prices) << endl;

    return 0;
}

