/*********************

Topic: Fibonacci Sequence

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

using namespace std;


int fibonacci1(int n) {
    if(n <= 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(n > 2) return fibonacci1(n - 1) + fibonacci1(n - 2);
}

int fibonacci2(int n) {
    if(n <= 0) return 0;
    if(n == 1 || n == 2) return 1;
    int DP[n] = {0};
    DP[0] = 1, DP[1] = 1;
    for(int i = 2; i < n; ++i) {
        DP[i] = DP[i-1] + DP[i-2];
    }

    return DP[n-1];
}

int fibonacci3(int n) {
    if(n <= 0) return 0;
    if(n == 1 || n == 2) return 1;
    int fn_1 = 1, fn_2 = 1, fn = 0; // fn_1 means F(n-1), fn_2 means F(n-2)

    for(int i = 3; i <= n; ++i) {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }

    return fn;
}

void MattrixNSquare(vector<vector<int>> &M, int k);
void multiply(vector<vector<int>> &M1, vector<vector<int>> &M2);

int fibonacci4(int n) {
    if(n <= 0) return 0;
    if(n == 1 || n == 2) return 1;

    vector<vector<int>> M = {{1, 1}, {1, 0}};

    MattrixNSquare(M, n - 1);

    return M[0][0];
}

void MattrixNSquare(vector<vector<int>> &M, int k) {
    if(k == 0 || k == 1) return;
    MattrixNSquare(M, k / 2);
    multiply(M, M);
    vector<vector<int>> unit = {{1, 1}, {1, 0}};
    if(k % 2 == 1) multiply(M, unit);
}

void multiply(vector<vector<int>> &M1, vector<vector<int>> &M2) {
    int fn_plus_one = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];
    int fn_right_top = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];
    int fn_left_bot = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];
    int fn_minus_one = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];
    M1[0][0] = fn_plus_one;
    M1[0][1] = fn_right_top;
    M1[1][0] = fn_left_bot;
    M1[1][1] = fn_minus_one;
}

int main() {

    for(int i = 1; i <= 15; ++i) {
        cout << fibonacci4(i) << endl;
    }

    return 0;
}
