/*******************************************

Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if
the key exists in the cache, otherwise return -1.

set(key, value) - Set or insert the value if the key is not already present.
When the cache reached its capacity, it should invalidate the least
recently used item before inserting a new item.

********************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class LRUNode {
public:
    int key, val;
    LRUNode *prev, *next;
    LRUNode() : prev(NULL), next(NULL), val(0) {}
    LRUNode(int k, int v) : prev(NULL), next(NULL), key(k), val(v) {}
};

class LRUCache {
private:
    int usage;
    int size;
    LRUNode *first, *last;
    map<int, LRUNode *> table;
    void attach(LRUNode *p) {
        p->prev = NULL;
        p->next = first;
        if(first) first->prev = p, first = p;
        else first = last = p;
    }
    void detach(LRUNode *p) {
        if(p->prev) p->prev->next = p->next;
        else first = p->next;
        if(p->next) p->next->prev = p->prev;
        else last = p->prev;
        p->prev = p->next = NULL;
    }

public:
    LRUCache(int capacity) : size(capacity), usage(0), first(NULL), last(NULL) {}
    int get(int key) {
        LRUNode *p;
        map<int, LRUNode *>::iterator iter;
        iter = table.find(key);
        if(iter == table.end()) return -1;
        p = iter->second;
        detach(p);
        attach(p);
        return first->val;
    }

    void set(int key, int value) {
        LRUNode *p;
        map<int, LRUNode *>::iterator iter;
        iter = table.find(key);
        if(iter == table.end()) {
            if(usage == size) {
                p = last;
                table.erase(p->key);
                detach(p);
                delete p;
                usage--;
            }
            p = new LRUNode(key, value);
            table.insert(pair<int, LRUNode *>(key, p));
            attach(p);
            usage++;
        } else {
            p = iter->second;
            p->val = value;
            detach(p);
            attach(p);
        }
    }
};


// test case will be updated~
int main()
{

    return 0;
}

