#include "headl.h" 
 struct TreeNode {
 int val; 
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int s;
    int e;
    Node* next;
    Node* pre;
    Node(int x, int y) : s(x), e(y), pre(nullptr), next(nullptr){};
};
class MyCalendar {
public:
    Node* root;
    MyCalendar() {
        root = new Node(-1, -1);
    }

    bool book(int start, int end) {
        if (not root->next)
        {
            root->next = new Node(start, end);
            return true;
        }
        else
        {
            Node* p = root;
            Node* a = root->next;
            while (a and a->s < start)
            {
                p = a;
                a = a->next;
            }
            if (not a)
            {
                if (p->e <= start)
                {
                    p->next = new Node(start, end);
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (a->s == start) return false;
            else
            {
                if (p->e <= start and a->s >= end)
                {
                    p->next = new Node(start, end);
                    p->next->next = a;
                    return true;
                }
                else
                {
                    return false;
                }
                
            }
        }

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
