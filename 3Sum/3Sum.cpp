/*******************************************

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

// 此题折腾了很久，并且参考了不少别人的解法，所以原谅我写很多废话注释//

********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {

    int n = (int)num.size();
    vector<vector<int> > result;
    sort(begin(num), end(num));

    for(int i = 0; i < n-2; i++) {
        // 下面这个if continue的作用在于防止出现重复的组合。所以有重复的项出现就跳过。
        // 为什么不能用 num[i] == num[i+1]? 答案跟 为什么要用do while 而不能用while类似。
        //  i表示本次循环将要使用的项，i-1表示上次循环中已经检查过的项，所以这样写能保证
        // 这个元素(比如-2,0,0,0,0,4，第一个0能作为num[i]进入while循环)
        // 至少经历一遍下面的while循环。而如果写成num[i] == num[i+1], 则有可能
        // 直接跳到相同序列的最后一项，加入有序列0,0,0,0,这么写将直接跳到最后一个0，从而
        // 错过0,0,0的组合。确实很巧妙，既不会产生重复，又不会错过具有相同项的组合。
        if(i > 0 && num[i-1] == num[i]) continue;
        int x = i + 1, y = n - 1;
        while(x < y) {
            int sum = num[i] + num[x] + num[y];
            if(sum < 0) x++;
            else if(sum > 0) y--;
            else {
                result.push_back(vector<int>({num[i], num[x], num[y]}));
                do {x++;} while(x < y && num[x-1] == num[x]);
                do {y--;} while(x < y && num[y+1] == num[y]);
            }
        }
    }

    return result;
}



int main() {

    std::vector<int> v1 = {-5, -3, -1, -1, 0, 0, 0, 0, 1, 2, 3, 5, -2, -3, 6, -15, 10};

    vector<vector<int> > result1 = threeSum(v1);
    for(auto iter1 : result1) {
        for(auto iter2 : iter1) {
            cout << iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}
