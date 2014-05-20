/*******************************************

Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

Examples:

Input:  Array {1, 2, 3}
Output: A Balanced BST
     2
   /  \
  1    3

Input: Array {1, 2, 3, 4}
Output: A Balanced BST
      3
    /  \
   2    4
 /
1

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int start = 0, ending = num.size() - 1;
        return Helper(num, start, ending);
    }

    TreeNode *Helper(vector<int> &num, int start, int ending){
        if(start > ending)  return NULL;
        int mid = (start + ending) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = Helper(num, start, mid - 1);
        root->right = Helper(num, mid + 1, ending);
        return root;
    }
};

int main()
{


    return 0;
}

