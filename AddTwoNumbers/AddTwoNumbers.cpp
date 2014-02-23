/*******************************************

You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their ListNodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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

    ListNode *addForlink(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *res, *pre = NULL;
        int c = 0;
        while(l1 && l2) {
            int t = l1->val + l2->val + c;
            ListNode *r = new ListNode(t % 10);

            if(pre) {
                pre->next = r;
                pre = r;
            }
            else pre = res = r;
            c = t / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int t = l1->val + c;
            ListNode *r = new ListNode(t % 10);

            pre->next = r;
            pre = r;
            c = t / 10;
            l1 = l1->next;
        }

         while(l2) {
            int t = l2->val + c;
            ListNode *r = new ListNode(t % 10);

            pre->next = r;
            pre = r;
            c = t / 10;
            l2 = l2->next;
        }
        if(c > 0) {
            ListNode *r = new ListNode(c);
            pre->next = r;
            pre = r;
        }

        return res;
    }


int main()
{
    int n = 4;
    int a[] = {1, 2, 9, 3};
    int m = 3;
    int b[] = {9, 9, 2};

    ListNode *p = init(a, n);
    ListNode *q = init(b, m);

    cout << "The linkedlist a : "; print(p);
    cout << "                 +  " << endl;
    cout << "The linkedlist b : "; print(q);
    ListNode *result = addForlink(p, q);
    cout << "=========================" << endl;
    cout << "        Equal to : ";
    if(result) print(result);

    return 0;
}

