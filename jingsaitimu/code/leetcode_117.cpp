#include "headl.h"
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    void get(Node *&a, Node *&b, Node *&c)
    {
        if (b == NULL)
            b = a;
        else
        {
            b->next = a;
            b = a;
        }
        if (c == NULL)
            c = a;
    }
    Node *connect(Node *root)
    {
        Node *start = root;
        while (start != NULL)
        {
            Node *ns = NULL;
            Node *last = NULL;
            while (start != NULL)
            {
                if (start->left != NULL)
                    get(start->left, last, ns);
                if (start->right != NULL)
                    get(start->right, last, ns);
                start = start->next;
            }
            start = ns;
        }
        return root;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution *a = new Solution();
}
