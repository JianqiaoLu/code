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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (not root) return root;
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) root->right = deleteNode(root->left, key);
        else
        {
            if (not root->left and not root->right)
            {
                root = nullptr;
            }
            else if (root->right)
            {
                TreeNode* rs = root->right;
                while (rs->left)
                {
                    rs = rs->left;
                }
                int k = root->val;
                root->val = rs->val;
                rs->val = k;
                root->right = deleteNode(root->right, k);
            }
            else
            {
                TreeNode* ls = root->left;
                while (ls->right)
                {
                    ls = ls->right;
                }
                int k = root->val;
                root->val = ls->val;
                ls->val = k;
                root->left = deleteNode(root->left, k);
            }
        }
        return root;
    }
    TreeNode* get(TreeNode* r, int k)
    {
        if (r == nullptr) return nullptr;
        if (r->val == k) return r;
        else if (r->val > k) return get(r->left, k);
        else return get(r->right, k);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
