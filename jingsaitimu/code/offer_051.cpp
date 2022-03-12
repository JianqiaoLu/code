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
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        get(root);
        return ans;
    }
    int get(TreeNode* root)
    {
        int ans1 = 0, ans2 = 0;
        if (root->left)
        {
            ans1 = get(root->left);
            ans = max(ans1, ans);
        }
        if (root->right)
        {
            ans2 = get(root->right);
            ans = max(ans2, ans);
        }
        ans = max(ans, root->val + max(ans1, ans2));
        ans = max(ans, root->val + ans1 + ans2);
        return max(ans1, ans2) + root->val;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
