/*******************************************

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *prev = NULL, *curr;
        if(root) s.push(root);

        while(!s.empty()) {
            curr = s.top();
            if(prev && (prev == curr->right)) {
                s.pop();
            } else if((prev == curr->left && curr->right == NULL)) {
                result.push_back(curr->val);
                s.pop();
            } else if(prev == curr->left && curr->right != NULL){
                result.push_back(curr->val);
                s.push(curr->right);
            } else {
                if(curr->left) s.push(curr->left);
                else {
                    result.push_back(curr->val);
                    if(curr->right) s.push(curr->right);
                    else s.pop();
                }
            }
            prev = curr;
        }

        return result;
    }
};

int main()
{


    return 0;
}

