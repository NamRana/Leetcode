class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int n = nums.size();
        int i = 0; // pointer for even indices
        int j = 1; // pointer for odd indices

        // Continue until we reach the end of the array
        while (i < n && j < n) {

            // If nums[i] is even, it's correctly placed
            if (nums[i] % 2 == 0) {
                i += 2;
            }
            // If nums[j] is odd, it's correctly placed
            else if (nums[j] % 2 == 1) {
                j += 2;
            }
            // Both are misplaced → swap them
            else {
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }

        return nums;
    }
};
