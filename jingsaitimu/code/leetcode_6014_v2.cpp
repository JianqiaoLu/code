#include "headl.h" 
class Node
{
public:
    char val;
    Node* pre;
    Node* next;
    Node(char v)
    {
        val = v;
        pre = nullptr;
        next = nullptr;
    }
};
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        Node* head = new Node('-1');
        Node* cur = head;
        Node* tail = new Node('-1');
        sort(s.begin(), s.end(), greater<char>());
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            Node* a = new Node(s[i]);
            cur->next = a;
            cur = cur->next;
        }
        cur->next = tail;
        bool flag = false;
        int k = 1;
        string ans;
        delnode(head->next);
        ans.push_back(s[0]);
        int repeat = 1;
        while (flag)
        {
            flag = false;
            Node* cur = head->next;
            if (cur->val == ans[k - 1] and repeat < repeatLimit)
            {
                ans.push_back(cur->val);
                k++;
                repeat++;
                flag = true;
                delnode(cur);
            }
            else if (cur->val == ans[k - 1] and repeat >= repeatLimit)
            {
                while (cur->val == ans[k - 1])
                {
                    cur = cur->next;
                }
                ans.push_back(cur->val);
                k++;
                repeat = 1;
                flag = true;
                delnode(cur);
            }
            else
            {
                ans.push_back(cur->val);
                k++;
                repeat = 1;
                flag = true;
                delnode(cur);
            }
            if(k == n) return ans;
        }
        return ans;
    }
    void delnode(Node* a)
    {
        a->pre->next = a->next;
        a->next->pre = a->pre;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
