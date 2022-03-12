#include "headl.h" 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> ans;
        vector<vector<int>> ans2;
        ans.push(root);
        while (!ans.empty())
        {
            queue<TreeNode*> ans1;
            vector<int> a;
            while (!ans.empty())
            {
                TreeNode* p = ans.front();
                ans.pop();
                a.push_back(p->val);
                if (p->left != NULL)
                {
                    ans1.push(p->left);
                }
                if (p->right != NULL)
                {
                    ans1.push(p->right);
                }
            }
            ans2.push_back(a);
            ans = ans1;
        }
        return ans2;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
