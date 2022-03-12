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
    TreeNode* convertBST(TreeNode* root) {
        if(not root) return nullptr;
        int sum = get(root);
        go(root, sum);
        return root;
    }
    int get(TreeNode* root)
    {
        int v = root->val;
        if (root->left) v += get(root->left);
        if (root->right) v += get(root->right);
        return v;
    }
    void go(TreeNode* root, int& sum)
    {
        if (not root) return;
        go(root->left, sum);
        int cur = root->val;
        root->val = sum;
        sum -= cur;
        go(root->right, sum);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
