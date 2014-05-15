/*******************************************

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
        // Save all node's value into result
        vector<int> result;

        // Create an empty stack and push root to it
        stack<TreeNode *> s;
        if(root) s.push(root);

        /* Pop all items one by one. Do following for every popped item
           a) save it into result and then pop it
           b) push its right child
           c) push its left child
           Note that right child is pushed first so that left is processed first */
        while(!s.empty()) {
        Treenode *currNode = s.top();
        result.push_back(currNode->val);
        s.pop();

        if(currNode->right)
            s.push(currNode->right);
        if(currNode->left)
            s.push(currNode->left);
        }

    return result;
    }
};

int main()
{


    return 0;
}

