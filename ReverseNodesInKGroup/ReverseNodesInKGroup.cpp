/*******************************************

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

********************************************/

#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* init(int a[], int n) {
    ListNode *head = NULL, *p;
    for(int i = 0; i < n; i++) {
        ListNode *nd = new ListNode(a[i]);
        if(i == 0) {
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

void print(ListNode *head) {
    while(head) {
        cout << head->val << "  ";
        head = head->next;
    }
    cout << endl;
}

ListNode *push(ListNode *head) {
    ListNode *newNode = new ListNode(-1);
    newNode->next = head;
    head = newNode;
    return head;
}

ListNode *pop(ListNode *head) {
    ListNode *delNode = head;
    head = head->next;
    delete delNode;
    return head;
}

// deleteDuplicates() Function by recursion.

ListNode *reverseKGroup(ListNode *head, int k) {
    if(head == NULL || head->next == NULL || k < 2) return head;

    ListNode *prev, *next, *last;
    ListNode *rprv, *rcur, *rnxt;
    int i = 0;
    prev = NULL;
    next = head;
    while(next != NULL) {
        i = 1;
        last = next;
        while(next && i < k) next = next->next, i++;
        if(next == NULL) break;
        next = next->next;
        rprv = NULL;
        rcur = last;
        while(rcur != next) {
            rnxt = rcur->next;
            rcur->next =rprv;
            rprv = rcur;
            rcur = rnxt;
        }
        if(prev != NULL) prev->next = rprv;
        else head = rprv;
        prev = last;
        last->next = next;
    }

    return head;
}




int main()
{
    int n = 12;
    int a[] = {1, 2, 2, 2, 8, 8, 8, 6, 6, 2, 5, 5};
   // int m = 3;
   // int b[] = {9, 9, 2};

    ListNode *p = init(a, n);
   // ListNode *q = init(b, m);


    ListNode *result = reverseKGroup(p, 3);
    cout << "=========================" << endl;

    if(result) print(result);

    return 0;
}

