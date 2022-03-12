#include "headl.h" 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        ttos(root, ans);
        return ans;
    }
    void ttos(TreeNode* root, string& ans)
    {
        if (not root)
        {
            ans += "null,";
            return;
        }
        else
        {
            ans += get(root->val);
            ttos(root->left, ans);
            ttos(root->right, ans);
        }
    }
    string get(int v)
    {
        string a = "";
        bool flag = true;
        if (v < 0)  flag = false;
        v = abs(v);
        while (v != 0)
        {
            a.push_back(v % 10 + '0');
            v /= 10;
        }
        if (not flag) a += "-";
        reverse(a.begin(), a.end());
        a += ",";
        return a;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int a = 0;
        return stot(data, a);
    }
    TreeNode* stot(string data, int& l)
    {
        string b = "";
        TreeNode* c;
        while (data[l] != ',')
        {
            b.push_back(data[l]);
            l++;
        }
        l++;
        if (b == "null")
        {
            return NULL;
        }
        else
        {
            c = new TreeNode(stov(b));
            c->left = stot(data, l);
            c->right = stot(data, l);
        }
        return c;
    }
    int stov(string s)
    {
        int ans = 0;
        if (s[0] == '-')
        {
            for (int i = 1; i < s.size(); i++)
            {
                ans = ans * 10 + (s[i] - '0');
            }
            ans = -ans;
        }
        else
        {
            for (auto i : s) ans = ans * 10 + (i - '0');
        }

        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);

}
