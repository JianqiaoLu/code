#include "headl.h" 
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> ans = get(root);
        return ans[k - 1];
    }
    vector<int> get(TreeNode* root)
    {
        vector<int> ans;
        if (root == NULL) return ans;
        else {
            vector<int> a, b;
            a = get(root->right);
            b = get(root->left);
            for (int i = 0; i < a.size(); i++) ans.push_back(a[i]);
            ans.push_back(root->val);
            for (int i = 0; i < b.size(); i++) ans.push_back(b[i]);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
