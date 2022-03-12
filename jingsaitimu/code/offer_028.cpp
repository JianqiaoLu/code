#include "headl.h" 
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:
    Node* c;
    Node* flatten(Node* head) {
        Node* b = head;
        get(b);
        return head;
    }
    void get(Node* a)
    {
        if (not a->next and not a->child)
        {
            c = a;
            return;
        }
        else if (not a->child)  a = a->next;
        else
        {
            Node* nxt = a->next;
            a->next = a->child;
            a->child->prev = a;
            get(a->child);
            a->child = nullptr;
            c->next = nxt;
            nxt->prev = c;
            a = nxt;
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
}
