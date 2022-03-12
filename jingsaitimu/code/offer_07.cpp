struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include "headl.h" 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
        {
            return nullptr;
        }

        int trv = preorder[0];
        TreeNode a1 = TreeNode(trv);
        TreeNode* root = &a1;
        int loc;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == trv)
            {
                loc = i;
                break;
            }
        }
        vector<int> a(preorder.begin() + 1, preorder.begin() + loc);
        vector<int> b(preorder.begin() + loc + 1, preorder.end());
        vector<int> c(inorder.begin(), inorder.begin() + loc);
        vector<int> d(inorder.begin() + loc + 1, inorder.end());
        root->left = buildTree(a, b);
        root->right = buildTree(c, d);
        return root;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);

}
