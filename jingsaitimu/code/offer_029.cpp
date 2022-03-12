#include "headl.h" 
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* a = new Node(insertVal);
        if (head == nullptr)
        {
            a->next = a;
            return a;
        }
        Node* b = head;
        Node* m = b;
        int v = m->val;
        b = b->next;
        while (b != head)
        {
            if (v < b->val)
            {
                v = b->val;
                m = b;
            }
            b = b->next;
        }
        if (v< insertVal)
        {
            a->next = m->next;
            m->next = a;
        }
        else
        {
           Node* to = m->next; 
           Node* pre = m;
           while (to->val < insertVal and to!= m)
           {
               to = to->next;
               pre = to;
           }
           pre ->next = a;
           a ->next =  to;
        }
        return head;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
