/*******************************************

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

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

int minDepth(TreeNode *root) {
    if(root == NULL) return 0;
    queue<TreeNode *> nQ;
    nQ.push(root);
    int level = 1;
    while(!nQ.empty()) {
        int levelSize = nQ.size();

        while(levelSize--) {
            root = nQ.front();
            nQ.pop();
            if(root->left) nQ.push(root->left);
            if(root->right) nQ.push(root->right);
            if(root->left == NULL && root->right == NULL) return level;
        }
        level++;
    }
}


int main()
{
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(4);
    tree->right = new TreeNode(3);

    cout << minDepth(tree) << endl;

    return 0;
}

