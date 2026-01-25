class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            maxFreq = max(maxFreq, freq[nums[right]]);

            while ((right - left + 1) - maxFreq > k) {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, maxFreq);
        }

        return ans;
    }
};
