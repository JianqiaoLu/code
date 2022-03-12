#include "headl.h" 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* l = new ListNode(0);
        l->next = head;
        ListNode* r ;
        while (l!= NULL)
        {
            if(l->val == val) r->next = l->next;
            r = l;
            l = l->next;
        }
        return head;

    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
