#include "headl.h" 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class BSTIterator {
public:
    queue<TreeNode*> ans;
    BSTIterator(TreeNode* root) {
        get(root);
    }
    void get(TreeNode* root)
    {
        if (not root)
        {
            return;
        }
        get(root->left);
        ans.push(root);
        get(root->right);
    }

    int next() {
        int v = ans.front()->val;
        ans.pop();
        return v;
    }

    bool hasNext() {
        return not ans.empty();
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
