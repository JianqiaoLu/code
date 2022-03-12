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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        get(root, 0);
        return ans;
    }
    void get(TreeNode* root, int sum)
    {
        sum = sum * 10 + root->val;
        if (not root->left and not root->right) ans += sum;
        if (root->left) get(root->left, sum);
        if (root->right) get(root->right, sum);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
