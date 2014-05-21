/*******************************************

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which
the depth of the two subtrees of every node never differ by more than 1.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        if(getBalance(root) != -1) return true;
        return false;
    }

    int getBalance(TreeNode *node) {
        if(node == NULL) return 0;
        int left = getBalance(node->left);
        if(left == -1) return -1;
        int right = getBalance(node->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return left > right ? left + 1 : right + 1;
    }
};



int main()
{


    return 0;
}

