/*******************************************

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_map>




using namespace std;

 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

int maxPoints(vector<Point> &points) {
    if(points.size() == 1) return 1;
    unordered_map<float, int> slope_map;
    unordered_map<float, int>::iterator iter;
    int result = 0;
    if(points.empty()) return 0;
    for(int i = 0; i < points.size(); ++i) {
        int maxNum = 0;
        int vertical = 1;
        int same = 0;
        int x = points[i].x;
        int y = points[i].y;
        for(int j = 0; j < points.size(); ++j) {
            if(j != i) {
                if(points[j].x == x && points[j].y != y) vertical++;
                if(points[j].x == x && points[j].y == y) same++;
                else if(points[j].x != x) {
                    float s = (float)(points[j].y - y) / (float)(points[j].x - x);
                    if((iter = slope_map.find(s)) == slope_map.end()) slope_map.insert({s, 2});
                    else iter->second++;
                }
            }

        }
        maxNum = std::max(maxNum, vertical);
        iter = slope_map.begin();
        while(iter != slope_map.end()) {
            maxNum = std::max(maxNum, iter->second);
            iter++;
        }

        maxNum += same;

        slope_map.clear();
        result = std:: max(result, maxNum);
    }

    return result;
}


int main()
{
    vector<Point> points;
    Point a = Point(1, 2);
    Point b = Point(0, 0);
    Point c = Point(1, 1);
    Point d = Point(1, 1);
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);

    cout << maxPoints(points) << endl;

    return 0;
}

