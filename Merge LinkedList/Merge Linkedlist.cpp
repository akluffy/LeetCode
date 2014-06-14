/*******************************************

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_set>



using namespace std;

void appendNodeAndAdvance(ListNode **head, ListNode **tail, ListNode **node) {
    appendNode(*node, head, tail);
    *node = (*node)->next;
}

void appendNode(ListNode *(&node), ListNode **head, ListNode **tail) {
    *head ? (*tail)->next = node : *head = node;
    *tail = node;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode *tail =  NULL;
    while(l1 && l2) {
        appendNodeAndAdvance(&head, &tail, l1->val < l2->val ? &l1 : &l2);
    }

    if(l1) appendNode(l1, &head, &tail);
    if(l2) appendNode(l2, &head, &tail);

    return head;
}


int main()
{


    return 0;
}

