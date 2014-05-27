/*******************************************

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

void flatten(TreeNode *root) {
    if(root == NULL) return;

    if(root->right) flatten(root->right);
    if(root->left) flatten(root->left);

    TreeNode *tail = root->left, *temp =root->right;
    if(tail) {
        while(tail->right) tail = tail->right;
        root->right = root->left;
    }
    root->left = NULL;
    if(tail) tail->right = temp;

}





int main()
{



    return 0;
}

