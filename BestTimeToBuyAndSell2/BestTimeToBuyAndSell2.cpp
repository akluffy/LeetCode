/*******************************************

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;



class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max = 0;
        int sum = 0;
        for(int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if(diff > 0) sum += diff;
        }

        return sum;
    }
};

int main()
{
    vector<int> v(5,0);
    v[0] = 5;
    Solution s;

    cout << s.maxProfit(v) << endl;

    return 0;
}

