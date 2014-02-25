/*******************************************

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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

ListNode *deleteDuplicates(ListNode *head) {
    if(head == NULL || head->next == NULL) return head;

    ListNode *dummy = head->next;
    if(head->val == dummy->val) {
        while(dummy && head->val == dummy->val) {
            ListNode *p = dummy;
            dummy = dummy->next;
            delete p;
        }
        head->next = deleteDuplicates(dummy);
        return head;
    } else {
        head->next = deleteDuplicates(dummy);
        return head;
    }
}

// traverse version //

ListNode *deleteDuplicates2(ListNode *head) {
    if(head == NULL) return head;
    ListNode *prev = head, *cur = head->next;

    while(cur != NULL) {
        if(prev->val == cur->val) {
            prev->next = cur->next;

            ListNode *p = cur;
            cur = cur->next;
            delete p;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
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


    ListNode *result = deleteDuplicates2(p);
    cout << "=========================" << endl;

    if(result) print(result);

    return 0;
}

