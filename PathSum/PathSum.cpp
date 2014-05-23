/*******************************************

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) return false;
        bool result = false;
        int remainder = sum - root->val;
        if(remainder == 0 && root->left == NULL && root->right == NULL) return true;

        if(root->left) {
            if(result = hasPathSum(root->left, remainder)) //注意这里是幅值，不是比较。result如果是真就返回
                return true;
        }
        if(root->right) {
            if(result = hasPathSum(root->right, remainder))  //注意这里是幅值，不是比较。result如果是真就返回
                return true;
        }
        return result;
    }
};


int main()
{


    return 0;
}

