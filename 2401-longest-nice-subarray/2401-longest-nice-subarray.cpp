class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int mask = 0;   // OR of elements in current window
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // If adding nums[right] causes conflict,
            // shrink window from the left
            while ((mask & nums[right]) != 0) {
                mask ^= nums[left];  // remove nums[left] bits
                left++;
            }

            // Safe to include nums[right]
            mask |= nums[right];

            // Update answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
