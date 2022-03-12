#include "headl.h" 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* l = headA;
       ListNode* r = headB;
       while(l!=nullptr or r != nullptr)
       {
           if(l == nullptr)  l = headB;
           if(r == nullptr)  r = headA;
           if(l == r ) return l; 
           l = l->next;
           r = r-> next;
       }
       return nullptr;
}
}
;

int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
