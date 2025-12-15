/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /**
 Create a dummy node for result list
 keep a carry variable
 while l1 and l2 or carry exists
 add digits + carry
 create a new node with sum%10
 update carry sum/10
 return result list
 **/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        int carry=0;
        ListNode* cur=dummy;

        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int sum=carry;

            if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;
            }

            cur->next=new ListNode(sum%10);

            carry=sum/10;
            
            cur=cur->next;
        }
        return dummy->next;
   }
};