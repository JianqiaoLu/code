#include "headl.h" 
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);

}
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
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<TreeNode*> tod;
        tod.push_back(root);
        while (tod.size())
        {
            TreeNode* a = tod.back();
            tod.pop_back();
            if (a->val == val)
            {
                return a;
            }
            else
            {
                if (a->left != nullptr)
                {
                    tod.push_back(a->left);
                }
                if (a->right != nullptr)
                {
                    tod.push_back(a->right);
                }

            }
        }
        return NULL;
    }
};
