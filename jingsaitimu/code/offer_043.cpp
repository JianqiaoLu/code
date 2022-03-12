#include "headl.h" 
class CBTInserter {
public:
    queue<Treenode*> ans;
    TreeNode* r;
    CBTInserter(TreeNode* root) {
        ans.push(root)
            r = root;
    }
    int insert(int v) {
        TreeNode* a;
        bool isleft;
        while (not ans.empty())
        {
            a = ans.front();
            if (a->left) ans.push(a->left);
            else
            {
                isleft = true;
                break;
            }
            if (a->right) ans.push(a->right);
            else
            {
                isleft = false;
                break;
            }
            ans.pop();
        }
        if(isleft)  a->left = new TreeNode(v);
        else a->right= new TreeNode(v);
        return a->val;
    }

    TreeNode* get_root() {
        return r;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
