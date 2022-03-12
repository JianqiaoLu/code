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
    vector<int> rightSideView(TreeNode* root) {
        if(not root) return ans;
        get(root);
        return ans;
    }
    void get(TreeNode* root)
    {
        ans.push_back(root->val);
        if (root->right)
            get(root->right);
        else if (root->left)
            get(root->left);
        else return;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
