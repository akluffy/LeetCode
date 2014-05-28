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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(ListNode *&list, int start, int end) {
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode *leftChild = helper(list, start, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = helper(list, mid + 1, end);
        return parent;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *temp = head;
        while(temp != NULL) {
            temp = temp->next;
            n++;
        }
        return helper(head, 0, n-1);
    }
};




int main()
{


    return 0;
}

