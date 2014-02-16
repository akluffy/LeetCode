/*******************************************

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

********************************************/

#include <iostream>
#include <vector>

using namespace std;

  int factorial(int n) {
        int result = 1;
        int a = 1;
        while(a <= n) {
            result *= a;
            a++;
        }
        return result;
    }

    int combinatorics(int n, int x) {
        if(n == 0) return 0;
        int up = 1, down = 1;
        int smaller;
        if(x > (n - x)) smaller = n - x;
        else smaller = x;
        while(smaller > 0) {
            up *= n--;
            down *= smaller--;
        }

        return  up / down;
    }

    int climbStairs(int n) {
        int ct1 = 0 , ct2 = 0, result = 0;
        for(int i = 0; i <= n / 2; i++) {
            ct2 = i;
            ct1 = n - 2 * ct2;
            if((ct1 + ct2 * 2) != n) continue;
            result += combinatorics(ct1+ct2, ct2);
        }

        return result;
    }

// 斐波那契数列 。 楼梯其实就是这个数列，太奸诈了。 以下才是正解
    int climbStairs2(int n) {
        int fn_2 = 1, fn_1 = 2;
        if(n == 1) return fn_2;
        if(n == 2) return fn_1;
        int fn;
        for(int i = 3; i <= n; i++) {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn;
    }

int main() {

    cout << combinatorics(24, 12) << " *********** " << endl;

  for(int i = 0; i< 28; i++) {
    cout << climbStairs(i) << endl;
  }
    return 0;
}
