/*******************************************

Reference: http://fisherlei.blogspot.com/search?q=+Construct+Binary+Tree+from
感谢水中的鱼提供的详细思路，不过在他提供的代码里，好像把inorder的下标跟preorder的弄反了

Given preorder and inorder traversal of a tree, construct the binary tree.

Thought:

 step--1
        _______7______
       /              \
    __10__          ___2
   /      \        /
   4       3      _8
            \    /
             1  11
The preorder and inorder traversals for the binary tree above is:
inorder =   {4,10,3,1,7,11,8,2}
postorder = {4,1,3,10,11,8,2,7}


 step--2
The last node in postorder alwasy the root of the tree. We can break the tree like:
1st round:
inorder:   {4,10,3,1}, {7}, {11,8,2}
postorder: {4,1,3,10}, {11,8,2}, {7}
        _______7______
       /              \
    {4,10,3,1}       {11,8,2}
Since we alreay find that {7} will be the root, and in "inorder" sert,
all the data in the left of {7} will construct the left sub-tree.
And the right part will construct a right sub-tree.
We can the left and right part agin based on the preorder.


 step--3
2nd round
left part                            right part
postorder: {4}, {1,3}, {10}          {11,8}, {2}
inorder:   {4}, {10}, {3,1}          {11,8}, {2}
        _______7______
       /              \
    __10__          ___2
   /      \        /
  4     {3,1}   {11,8}
note that, {10} will be the root of left-sub-tree and {2} will be the root of right-sub-tree.

Same way to split {3,1} and {11,8}, yo will get the complete tree now.


 step--4
Same way to split {3,1} and {11,8}, yo will get the complete tree now.

        _______7______
       /              \
    __10__          ___2
   /      \        /
   4       3      _8
            \    /
             1  11
So, simulate this process from bottom to top with recursion as following code.


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

TreeNode *buildTree(vector<int> &postorder, int pS, int pE,
                    vector<int> &inorder,  int iS, int iE) {
    if(iS > iE) return NULL;
    int pivot = postorder[pE];
    int i = iS;
    while(i < iE) {
        if(inorder[i] == pivot) break;
        i++;
    }
    TreeNode *node = new TreeNode(pivot);

    node->left = buildTree(postorder, pS, pS + i - iS - 1, inorder, iS, i - 1); // i-is-1 为inroder中is到pivot之前那个点的距离
    node->right = buildTree(postorder, pS + i - iS, pE - 1, inorder, i + 1, iE);
    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main()
{

    return 0;
}

