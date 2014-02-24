/*******************************************

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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

ListNode *partition(ListNode *head, int x) {
    ListNode *frontHead = new ListNode(-1), *frontNode = frontHead;
    ListNode *backHead = new ListNode(-1), *backNode = backHead;
    while(head != NULL) {
        if(head->val < x) frontNode->next = head, frontNode = frontNode->next;
        else backNode->next = head,backNode = backNode->next;
        head = head->next;
    }
    backNode->next = NULL;
    frontNode->next = pop(backHead);

    return pop(frontHead);
}


int main()
{
    int n = 8;
    int a[] = {1, 2, 9, 3, 8, 13, 4, 6};
   // int m = 3;
   // int b[] = {9, 9, 2};

    ListNode *p = init(a, n);
   // ListNode *q = init(b, m);


    ListNode *result = partition(p, 5);
    cout << "=========================" << endl;

    if(result) print(result);

    return 0;
}

