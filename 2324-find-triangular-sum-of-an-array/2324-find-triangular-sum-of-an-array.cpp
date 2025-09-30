class Solution {
public:
   int triangularSum(vector<int>& nums) {
        // Keep reducing the array until only one element remains
        while (nums.size() > 1) {
            vector<int> newNums;
            for (int i = 0; i < nums.size() - 1; i++) {
                // Apply the rule: sum of consecutive elements % 10
                newNums.push_back((nums[i] + nums[i+1]) % 10);
            }
            // Replace nums with the reduced array
            nums = newNums;
        }
        // The only element left is the triangular sum
        return nums[0];
    }
};