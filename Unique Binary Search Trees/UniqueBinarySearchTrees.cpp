/*******************************************

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and
the nodes have the same value.

reference:
[1]http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// method 1 : recursion.
int numTrees(int n) {
    if(n == 0 || n == 1) return 1;

    int result = 0;

    for(int i = 1; i <= n; i++) {
        int left = numTrees(i - 1), right = numTrees(n - i);
        if(left == 0) result += right;
        else if(right == 0) result += left;
        else if(left && right) result += left * right;
    }

    return result;
}

// method 2 : dynamic programming
int numTrees2(int n) {
    vector<int> count(n + 1, 0);
    count[0] = 1;
    count[1] = 1;
    for(int i = 2; i < n; i ++) {
        for(int j = 0; j < i; j++) {
            count[i] += count[j] * count[i - j -1];
        }
    }

    return count[n];
}

int main()
{


    return 0;
}

