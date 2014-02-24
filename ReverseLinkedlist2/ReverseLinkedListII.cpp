/*******************************************

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.

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

// reverseBetween() Function for solving the problem.

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(head == NULL || m < 1 || n < 1 || m >= n) return head;
    head = push(head);
    ListNode *curNode = head, *lastNode = NULL;
    while(m > 0) {
        lastNode = curNode, curNode = curNode->next;
        m--;
        n--;
    }
    ListNode *preNode = NULL;
    while(n >= 0) {
        ListNode *nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
        n--;
    }
    lastNode->next->next = curNode;
    lastNode->next = preNode;

    return pop(head);
}


int main()
{
    int n = 8;
    int a[] = {1, 2, 9, 3, 8, 13, 4, 6};
   // int m = 3;
   // int b[] = {9, 9, 2};

    ListNode *p = init(a, n);
   // ListNode *q = init(b, m);


    ListNode *result = reverseBetween(p, 2, 7);
    cout << "=========================" << endl;

    if(result) print(result);

    return 0;
}

