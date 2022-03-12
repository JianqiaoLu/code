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
    vector<TreeNode*> ans;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        get(root);
        int i ;
        for (i = 0; i < ans.size(); i++)
        {
            if (ans[i]->val == p->val)
            {
                break;
            }
        }
        if (i != ans.size() - 1)
        {
            return ans[i+1];
        }
        else return nullptr;
        
    }
    void get(TreeNode* root)
    {
        if (not root) return;
        get(root->left);
        ans.push_back(root);
        get(root->right);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
