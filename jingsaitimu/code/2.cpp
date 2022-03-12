#include "headl.h" 
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout);  
  struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersbyrecursiion(l1,l2,0);
    };

    ListNode* addTwoNumbersbyrecursiion(ListNode* l1, ListNode* l2, int num)
    {
        if ((not l1) && (not l2) && (not num))
        {
            return new ListNode();
        }
        if ((not l1) && (not l2) && (num))
        {
            return new ListNode(1);
        }
        else if ((not l1) || (not l2))
        {
            if (not l1)
            {
                l1 = new  ListNode(0);
                return addTwoNumbersbyrecursiion(l1,l2,num);
            }
            else
            {
                l2 = new  ListNode(0);
                return addTwoNumbersbyrecursiion(l1,l2,num);
            }
            
        }
        else
        {
            ListNode* ansl = new ListNode((l1->val + l2->val)%10);
            int ans =  ((l1->val + l2->val) > 10  )? 1:0;
            ansl->next = addTwoNumbersbyrecursiion(l1->next,l2->next,ans);
            return ansl;
        }
    }


};
   
}
