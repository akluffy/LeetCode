/*******************************************

Given an array S of n integers, find three integers in S such that the sum
is closest to a given number, target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Discuss



********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int threeSumClosest(vector<int> &num, int target) {

    int n = (int)num.size();
    int closestNum;
    int dif;
    sort(begin(num), end(num));

    if(num.size() < 3) exit(-1);
    else if(num.size() >= 3) {
        closestNum = num[0] + num[1] + num[2];
        dif = abs(target - closestNum);
    }

    for(int i = 0; i < n-2; i++) {
        if(i > 0 && num[i-1] == num[i]) continue;
        int x = i + 1, y = n - 1;
        while(x < y) {
            int sum = num[i] + num[x] + num[y];
            if((sum - target) > 0 ) {
                do {y--;} while(x < y && num[y+1] == num[y]);
            }
            else if((sum - target) < 0) {
                do {x++;} while(x < y && num[x-1] == num[x]);
            }
            else {
                closestNum = target;
                break;
            }

            if(dif > abs(sum - target)) {
                dif = abs(sum - target);
                closestNum = sum;
            }
        }
    }

    return closestNum;
}



int main() {

    std::vector<int> v1 = {-5, -3, -1, -1, 0, 0, 0, 0, 1, 2, 3, 5, -2, -3, 6, -15, 10};
    int target = 10;

    cout << " The closest sum to " << target << " is " << threeSumClosest(v1, target) << endl;

    return 0;
}
