class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int components = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            // Start of a new component
            if (s.count(curr->val) && 
                (prev == nullptr || !s.count(prev->val))) {
                components++;
            }
            prev = curr;
            curr = curr->next;
        }

        return components;
    }
};
