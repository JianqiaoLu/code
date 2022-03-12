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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> pre;
        if (not root) return {};
        TreeNode* ans;
        pre.push(root);
        while (not pre.empty())
        {
            queue<TreeNode*> next;
            ans = pre.front();
            while (not pre.empty())
            {
                TreeNode* cur = pre.front();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
                pre.pop();
            }
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
