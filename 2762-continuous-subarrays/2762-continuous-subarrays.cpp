class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> minD, maxD; // store values
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Maintain increasing deque for minimum
            while (!minD.empty() && minD.back() > nums[right])
                minD.pop_back();
            minD.push_back(nums[right]);

            // Maintain decreasing deque for maximum
            while (!maxD.empty() && maxD.back() < nums[right])
                maxD.pop_back();
            maxD.push_back(nums[right]);

            // Shrink window if condition is violated
            while (maxD.front() - minD.front() > 2) {
                if (nums[left] == minD.front())
                    minD.pop_front();
                if (nums[left] == maxD.front())
                    maxD.pop_front();
                left++;
            }

            // All subarrays ending at `right` are valid
            ans += (right - left + 1);
        }

        return ans;
    }
};
