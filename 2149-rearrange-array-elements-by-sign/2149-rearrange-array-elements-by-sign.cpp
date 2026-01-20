class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos, neg;

        // Step 1: Separate positives and negatives
        for (int num : nums) {
            if (num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        vector<int> ans(nums.size());
        int p = 0, n = 0;

        // Step 2: Place numbers alternately
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                ans[i] = pos[p++];  // even index → positive
            else
                ans[i] = neg[n++];  // odd index → negative
        }

        return ans;
    }
};
