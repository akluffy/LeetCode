/*******************************************

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *first = root, *iter, *prev, *nextlevel;
        while(first) {
            iter = first;
            prev = NULL;
            nextlevel = NULL;
            while(iter) {
                nextlevel = nextlevel ? nextlevel : (iter->left ? iter->left : iter->right);
                if(prev) prev->next = iter->left ? iter->left : iter->right;
                if(iter->left) iter->left->next = iter->right;
                if(iter->right) prev = iter->right;
                else if(iter->left) prev = iter->left;
                iter = iter->next;
            }
            first = nextlevel;
        }

    }
};

int main()
{


    return 0;
}

