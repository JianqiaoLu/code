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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> pre;
        if (not root) return {};
        vector<int> ans ;
        pre.push(root);
        while (not pre.empty())
        {
            int a = pre.front()->val;
            queue<TreeNode*> next;
            while (not pre.empty())
            {
                TreeNode* cur  = pre.front();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
                a = max(a, cur->val);
                pre.pop();
            }
            ans.push_back(a);
            pre = next;
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
