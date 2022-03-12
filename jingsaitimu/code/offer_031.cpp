#include "headl.h" 
class Node
{
public:
    int val;
    int keey;
    Node* pre;
    Node* next;
    Node(int k, int v)
    {
        keey = k;
        val = v;
        pre = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    int k;
    Node* head;
    Node* tail;
    map<int, Node*> mm;
    LRUCache(int capacity) {
        cap = capacity;
        k = 0;
        head = new Node(-1, -1);
        head->next = tail;
        tail = new Node(-1, -1);
        tail->pre = head;
    }

    int get(int key) {
        if (mm.count(key) and mm[key])
        {
            delnode(mm[key]);
            movetotail(mm[key]);
            return  mm[key]->val;
        }
        else return -1;
    }

    void put(int key, int value) {
        if (mm.count(key) and mm[key])
        {
            mm[key]->val = value;
            delnode(mm[key]);
            movetotail(mm[key]);
        }
        else
        {
            if (k >= cap)
            {
                Node* abc = head->next;
                delnode(abc);
                mm[abc->keey] = nullptr;
                k--;
            }
            Node* abc = new Node(key, value);
            mm[key] = abc;
            movetotail(mm[key]);
            k++;
        }
    }
    void delnode(Node* a)
    {
        a->pre->next = a->next;
        a->next->pre = a->pre;
    }
    void movetotail(Node* a)
    {
        Node* nxt = tail->pre;
        tail->pre = a;
        a->next = tail;
        a->pre = nxt;
        nxt->next = a;
    }
};
