class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
         int n = nums.size();
        vector<int> inc_left(n, 1), inc_right(n, 1);

        // Compute length of increasing subarray ending at each index
        for (int i = 1; i < n; ++i)
            if (nums[i] > nums[i - 1])
                inc_left[i] = inc_left[i - 1] + 1;

        // Compute length of increasing subarray starting at each index
        for (int i = n - 2; i >= 0; --i)
            if (nums[i] < nums[i + 1])
                inc_right[i] = inc_right[i + 1] + 1;

        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            int k = min(inc_left[i], inc_right[i + 1]);
            ans = max(ans, k);
        }

        return ans;
    }
};