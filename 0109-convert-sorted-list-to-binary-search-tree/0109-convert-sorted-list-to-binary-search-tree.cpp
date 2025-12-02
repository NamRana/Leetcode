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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        //splitting list at prev
        if(prev)prev->next=nullptr;

        return slow; //it should be the middle one
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //base cases
        if(!head)return nullptr;
        if(!head->next)return new TreeNode(head->val);

        //Find middle element
        ListNode* mid=findMiddle(head);

        //middle will become root
        TreeNode* root=new TreeNode(mid->val);

        //left half build left subtree
        if(head!=mid){
            root->left=sortedListToBST(head);
        }

        root->right=sortedListToBST(mid->next);

        return root;
    }
};