#include "headl.h" 

int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    int ans1 = a->maxDepth([1,null,3,2,4,null,5,6]);
}
   

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        return getans(root);

    }
    int getans(Node* nd)
    {
        if (nd == nullptr)
        {
            return 0;
        }
        else
        {
            int maxdep = 0;
            for ( int i = 0; i < nd->children.size(); i++)
            {
                maxdep = max(getans(nd->children[i]) + 1,maxdep);
            }
            return maxdep;
        }
        
    }
};