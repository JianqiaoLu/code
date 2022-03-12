#include "headl.h" 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* l = head;
        ListNode* r = l;
        while(k>=1 ) r = r->next;
        while (r!= NULL)
        {
            l = l->next;
            r = r->next;
        }
        return l;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
