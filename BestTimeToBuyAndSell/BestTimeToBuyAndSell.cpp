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
        if(prices.size() < 2)   return 0;
        int m = prices[0];
        int dif = 0;
        for(int i = 1; i < prices.size(); i++) {
            m = std::min(m, prices[i]);
            dif = std::max(dif, prices[i] - m);

        }
        return dif;
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

