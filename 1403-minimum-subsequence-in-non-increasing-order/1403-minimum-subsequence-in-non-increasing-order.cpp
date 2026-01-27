class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Sort in non-increasing order
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> result;
        int pickedSum = 0;

        for (int num : nums) {
            pickedSum += num;
            result.push_back(num);

            if (pickedSum > totalSum - pickedSum) {
                break;
            }
        }

        return result;
    }
};
