/*******************************************

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

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
    void helper(vector<vector<int> > &result, vector<int> sub, TreeNode *root, int sum) {
        if(root == NULL) return;
        sub.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(sum == root->val)
                result.push_back(sub);
        }
        else {
            helper(result, sub, root->left, sum - root->val);
            helper(result, sub, root->right, sum - root->val);
        }
        sub.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> sub;
        helper(result, sub, root, sum);
        return result;
    }
};


int main()
{


    return 0;
}

