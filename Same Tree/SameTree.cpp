/*******************************************

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and
the nodes have the same value.

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



    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        if(p->val == q->val) {
            if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) return true;
        } else return false;

    }


int main()
{


    return 0;
}

