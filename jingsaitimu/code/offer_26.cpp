#include "headl.h" 
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B==NULL and A==NULL)
        {
            return true;
        }
        if(B ==NULL and A!= NULL) return false;
        
        if (A!= NULL)
        {
            if (A->val == B-> val)
            {
                if(get(A,B)) return true;
            }
            return isSubStructure(A->left, B) or isSubStructure(A->right, B);
        }
        return false;
        
        
        
    }
    bool get(TreeNode* A, TreeNode* B)
    {
        if (A == NULL and B == NULL)
        {
            return true;
        }
        else
        {
            if ((A == NULL and B != NULL) or (B == NULL and A != NULL))
            {
                return false;
            }
            if (A->val != B->val) return false;
            else
            {
                return get(A->left, B->left) and get(A->right, B->right);
            }
        }

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
}
