/*******************************************

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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

static void recur(ListNode *prev, ListNode *cur);

ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *dummy = head->next;
        if(head->val == dummy->val) {
            while(dummy && head->val == dummy->val) {
                ListNode *p = dummy;
                dummy = dummy->next;
                delete p;
            }
            delete head;
            return deleteDuplicates(dummy);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
}

void recur(ListNode *prev, ListNode *cur) {
        if(cur == NULL) return;

        if(prev->val == cur->val) {
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        }
        else {
            recur(prev->next, cur->next);
        }

}

// traverse version //

// deleteDuplicates2 不需要新开一个节点作为临时头节点
    ListNode *deleteDuplicates2(ListNode *head) {
        ListNode *prev, *cur, *next;
        prev = NULL;
        cur = head;
        while (cur) {
            next = cur->next;
            if (next && cur->val == next->val) {
                while (cur && next && cur->val == next->val) {
                    cur->next = next->next;
                    delete next;
                    next = cur->next;
                }
                delete cur;
                cur = next;
                if (prev) prev->next = cur;
                else head = cur;
            } else {
                prev = cur;
            }
            cur = next;
        }

        return head;
    }

ListNode *deleteDuplicates3(ListNode *head) {
    if(head == NULL) return head;

    ListNode *dummy = new ListNode(head->val + 1);
    dummy->next = head;
    ListNode *prev = dummy, *cur = head;
    while(cur != NULL) {
        bool duplicated = false;
        while(cur->next && cur->val == cur->next->val) {
            duplicated = true;
            ListNode *p = cur;
            cur= cur->next;
            delete p;
        }
        if(duplicated) {
            ListNode *p = cur;
            cur = cur->next;
            delete p;
            continue;
        }
        prev->next = cur;
        prev = prev->next;
        cur = cur->next;
    }
    prev->next = cur;
    head = dummy->next;
    delete dummy;

    return head;
}

int main()
{
    int n = 14;
    int a[] = {1, 1, 2, 2, 2, 7, 8, 8, 8, 6, 6, 2, 5, 5};
   // int m = 3;
   // int b[] = {9, 9, 2};

    ListNode *p = init(a, n);
   // ListNode *q = init(b, m);


    ListNode *result = deleteDuplicates(p);
    cout << "=========================" << endl;

    if(result) print(result);

    return 0;
}

