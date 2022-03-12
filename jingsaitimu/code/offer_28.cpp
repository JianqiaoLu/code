#include "headl.h" 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
          if(root == NULL) return true;
          return get(root->left,root->right);
    }
    bool get(TreeNode* a,TreeNode* b  )
    {
        if ((a == NULL and b != NULL) or (b == NULL and a != NULL) or (a->val != b->val))
        {
            return false;
        }
        return (get(a->left,b->right) and get(a->right,b->left));
        
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
