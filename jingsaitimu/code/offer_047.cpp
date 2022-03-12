#include "headl.h" 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return op(root);
    }
    TreeNode* op(TreeNode* root)
    {
        if (not root or get(root)) return nullptr;
        if (get(root->left)) root->left = nullptr;
        else  root->left = op(root->left);
        if (get(root->right)) root->right = nullptr;
        else root->right = op(root->right);
        return root;
    }
    bool get(TreeNode* root)
    {
        if (not root)  return true;
        if (root->val != 0) return false;
        else return get(root->left) and get(root->right);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
