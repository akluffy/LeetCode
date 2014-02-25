/*******************************************

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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

// rotateRight() Function for solving the problem.

ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || k == 0) return head;

        int len = 1;
        ListNode *p = head;
        while(p->next) {
            len++;
            p = p->next;
        }
        k = len - k % len;

        p->next = head;
        for(int step = 0; step < k; step++) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;

        return head;
}


int main()
{
    int n = 8;
    int a[] = {1, 2, 9, 3, 8, 13, 4, 6};
   // int m = 3;
   // int b[] = {9, 9, 2};

    ListNode *p = init(a, n);
   // ListNode *q = init(b, m);


    ListNode *result = rotateRight(p, 5);
    cout << "=========================" << endl;

    if(result) print(result);

    return 0;
}

