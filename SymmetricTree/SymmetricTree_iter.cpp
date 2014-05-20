/*******************************************

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        deque<TreeNode*> nodeQueue;
        nodeQueue.push_back(root);
        int currLevel = 1; // number of elements of current level;

        while(currLevel > 0) {
            int i = 0;
            while(i < currLevel) {
                TreeNode *p = nodeQueue[i];
                i++;
                if(p == NULL) continue;
                nodeQueue.push_back(p->left);
                nodeQueue.push_back(p->right);
            }
            int start = 0, ending = currLevel - 1;

            /*
                Note: all elements in the tree can not be -1.
            */
            while(start < ending) {
                TreeNode *p1 = nodeQueue[start];
                TreeNode *p2 = nodeQueue[ending];
                int l = p1 == NULL ? -1 : p1->val;
                int r = p2 == NULL ? -1 : p2->val;
                if(l != r) return false;
                start++;
                ending--;
            }
            nodeQueue.erase(nodeQueue.begin(), nodeQueue.begin() + currLevel);
            currLevel = nodeQueue.size();
        }

        return true;
    }
};

int main()
{


    return 0;
}

