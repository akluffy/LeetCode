/*******************************************

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <climits>


using namespace std;




struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        result.push_back(newInterval);
        for(int i = 0; i < intervals.size(); i++) {
            Interval tempInt = result.back();
            result.pop_back();
            Interval *curr = &intervals[i];
            if(curr->end < tempInt.start) {
                result.push_back(*curr);
                result.push_back(tempInt);
            } else if(curr->start > tempInt.end) {
                result.push_back(tempInt);
                result.push_back(*curr);
            } else {
                tempInt.start = std::min(curr->start, tempInt.start);
                tempInt.end = std::max(curr->end, tempInt.end);
                result.push_back(tempInt);
            }
        }

        return result;
    }
};


int main()
{



    return 0;
}

