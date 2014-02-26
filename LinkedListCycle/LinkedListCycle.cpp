/*******************************************

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

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

//

    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;

        ListNode *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }




int main()
{
    int n = 12;
    int a[] = {1, 2, 2, 2, 8, 8, 8, 6, 6, 2, 5, 5};
   // int m = 3;
   // int b[] = {9, 9, 2};

    ListNode *p = init(a, n);
    ListNode *q = p;

    while(q->next) q = q->next;
    q->next = p->next;

    bool answer = hasCycle(p);
    cout << answer;
    /*
    ListNode *result = reverseKGroup(p, 3);
    cout << "=========================" << endl;

    if(result) print(result);
    */
    return 0;
}

