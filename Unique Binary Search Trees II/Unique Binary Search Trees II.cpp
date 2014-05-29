/*******************************************

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

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

vector<TreeNode *> *helper(int start, int end) {
    vector<TreeNode *> *result = new vector<TreeNode *>();
    if(start > end) {
        result->push_back(NULL);
        return result;
    }
    for(int i = start; i<= end; i++) {
        vector<TreeNode *> *leftN = helper(start, i - 1);
        vector<TreeNode *> *rightN = helper(i + 1, end);
        for(int j = 0; j < leftN->size(); j++) {
            for(int k = 0; k < rightN->size(); k++) {
                TreeNode *node = new TreeNode(i);
                node->left = (*leftN)[j];
                node->right = (*rightN)[k];
                result->push_back(node);
            }
        }
    }
    return result;
}

vector<TreeNode *> generateTrees(int n) {
    if(n == 0) return *helper(1,0);
    return *helper(1, n);
}




int main()
{


    return 0;
}

