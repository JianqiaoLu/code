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
    vector<int> ans;
    bool findTarget(TreeNode* root, int k) {
        get(root);
        int l = 0, r = ans.size() - 1;
        while (l < r)
        {
            if (ans[l] + ans[r] > k) r--;
            else if (ans[l] + ans[r] < k) l++;
            else return true;
        }
        return false;

    }
    void get(TreeNode* root)
    {
        if (not root)return;
        get(root->left);
        ans.push_back(root->val);
        get(root->right);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}

