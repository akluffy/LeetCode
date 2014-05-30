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
preorder = {7,10,4,3,1,2,8,11}
inorder = {4,10,3,1,7,11,8,2}


 step--2
The first node in preorder alwasy the root of the tree. We can break the tree like:
1st round:
preorder:  {7}, {10,4,3,1}, {2,8,11}
inorder:   {4,10,3,1}, {7}, {11, 8,2}
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
preorder: {10}, {4}, {3,1}          {2}, {8,11}
inorder:  {4}, {10}, {3,1}          {11,8}, {2}
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


TreeNode *buildTree(vector<int> &preorder, int pS, int pE,       // pS: Start of preOrder; PE: End of preOrder
                    vector<int> &inorder,  int iS, int iE) {     // iS: Start of inOrder;  iE: End of inOrder
    if(iS > iE) return NULL;
    int pivot = preorder[pS];
    int i = iS;
    while(i < iE) {
        if(inorder[i] == pivot) break;   // i stands for ,in inOrder sequence, the length from start of inOrder to the root(pivot) which is the 1st element of PreOrder.
        i++;
    }
    TreeNode *node = new TreeNode(pivot);

    // pS + 1 become the new Start of left-subtree in preorder, the end then become i - iS + pS, in which i - is refers to the length of left-subtree
    node->left = buildTree(preorder, pS + 1, i - iS + pS, inorder, iS, i - 1); // for inOrder, start of left-subtree is the same: iS, the end become i - 1
    // For right-subtree, start of preorder equals the end of left-subtree + 1: (i - iS + pS) + 1.
    node->right = buildTree(preorder, i - iS + pS + 1, pE, inorder, i + 1, iE);
    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main()
{

    return 0;
}

