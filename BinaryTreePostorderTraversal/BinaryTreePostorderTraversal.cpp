/*******************************************

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) {

        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *prev = NULL, *curr;
        if(root) s.push(root);

        while(!s.empty()) {
            curr = s.top();
            if(prev && (prev == curr->left || prev == curr->right)) {
                result.push_back(curr->val);
                s.pop();
            } else if(curr->right == NULL && curr->left == NULL) {
                result.push_back(curr->val);
                s.pop();
            } else {
                if(curr->right) s.push(curr->right);
                if(curr->left) s.push(curr->left);
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

