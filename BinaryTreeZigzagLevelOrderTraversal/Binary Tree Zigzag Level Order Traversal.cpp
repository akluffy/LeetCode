/*******************************************

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

// Two stacks in turn save elements row by row~

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    if(root == NULL) return result;

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty()) {
        vector<int> row;
        while(!s1.empty()) {
            TreeNode *curr = s1.top();
            s1.pop();
            row.push_back(curr->val);
            if(curr->left) s2.push(curr->left);
            if(curr->right) s2.push(curr->right);
        }
        result.push_back(row);
        row.clear();
        while(!s2.empty()) {
            TreeNode *curr = s2.top();
            s2.pop();
            row.push_back(curr->val);
            if(curr->right) s1.push(curr->right);
            if(curr->left) s1.push(curr->left);
        }
        if(!row.empty()) result.push_back(row);
    }

    return result;
}




int main()
{



    return 0;
}

