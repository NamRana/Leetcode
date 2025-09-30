class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxLen = 0;
        int currLen = 0;

        for (int i = 0; i < n; i++) {
            // reset if number exceeds threshold
            if (nums[i] > threshold) {
                currLen = 0;
                continue;
            }

            // start new subarray if even and currLen = 0
            if (currLen == 0) {
                if (nums[i] % 2 == 0) currLen = 1;
            } 
            else {
                // check alternating parity
                if ((nums[i] % 2) != (nums[i-1] % 2)) {
                    currLen++;
                } else {
                    // restart subarray if current number is even
                    currLen = (nums[i] % 2 == 0) ? 1 : 0;
                }
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};