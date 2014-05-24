/*******************************************

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void HelpSum(TreeNode *root, int &sum, int path);

int sumNumbers(TreeNode *root) {
    int sum = 0, path = 0;
    HelpSum(root, sum, path);
    return sum;
}

void HelpSum(TreeNode *root, int &sum, int path) {
    if(root == NULL) return;
    path = path * 10 + root->val;
    if(root->left == NULL && root->right == NULL) {
        sum += path;
        return;
    }
    HelpSum(root->left, sum, path);
    HelpSum(root->right, sum, path);
}


int main()
{
    TreeNode *tree = new TreeNode(0);
    tree->left = new TreeNode(1);
    tree->right = new TreeNode(3);

    cout << sumNumbers(tree) << endl;

    return 0;
}

