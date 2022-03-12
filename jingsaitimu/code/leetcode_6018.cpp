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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mm;
        map<TreeNode*, bool> isfather;
        for (int i = 0; i < descriptions.size(); i++)
        {
            TreeNode* p;
            TreeNode* c;
            p = (mm.count(descriptions[i][0])) ? mm[descriptions[i][0]] : new TreeNode(descriptions[i][0]);
            c = (mm.count(descriptions[i][1])) ? mm[descriptions[i][1]] : new TreeNode(descriptions[i][1]);
            if (descriptions[i][2]) p->left = c;
            else p->right = c;
            mm[descriptions[i][0]] = p;
            mm[descriptions[i][1]] = c;
            if (not isfather.count(p))
            {
                isfather[p] = false;
            }
            isfather[c] = true;
        }
        for (auto iter = isfather.begin(); iter != isfather.end(); iter++) {
            if (not iter->second)  return iter->first;
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
