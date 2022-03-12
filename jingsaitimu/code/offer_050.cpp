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
    int target;
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        if(not root) return 0;
        return getsum(root);
    }
    int getsum(TreeNode* root)
    {
        int sum = target, ans1 = 0, ans2 = 0, ans3 = 0;
        get(root, sum, ans1);
        if (root->left) ans2 = getsum(root->left);
        if (root->right) ans3 = getsum(root->right);
        return ans1 + ans2 + ans3;
    }

    void get(TreeNode* root, int sum, int& ans)
    {
        sum -= root->val;
        if (sum == 0)
        {
            ans++;
        }
        if (root->left) get(root->left, sum, ans);
        if (root->right) get(root->right, sum, ans);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
