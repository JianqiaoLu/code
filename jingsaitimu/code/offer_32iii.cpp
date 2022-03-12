#include "headl.h" 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> ans;
        vector<vector<int>> aa;
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
            aa.push_back(a);
            ans = ans1;
        }
        int i = 0;
        while( i < aa.size())
        {
            reverse(aa[i].begin(),aa[i].end());
            i = i + 2;
        }
        return aa;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
