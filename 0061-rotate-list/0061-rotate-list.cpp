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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0) return head;

        //step1: find length and tail
        ListNode* tail=head;
        int n=1;
        while(tail->next){
            tail=tail->next;
            n++;
        }

        //make circular link
        tail->next=head;
        
        k=k%n;
        if(k==0){
            tail->next=NULL;
            return head;
        }

        int stepsToNewTail=n-k;
        ListNode* newTail=head;

        for(int i=1;i<stepsToNewTail;i++){
            newTail=newTail->next;
        }

        ListNode* newHead=newTail->next;

        newTail->next=NULL;
        return newHead;
    }

};