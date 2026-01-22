class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        // Helper lambda to check if array is non-decreasing
        auto isSorted = [&](vector<int>& a) {
            for (int i = 1; i < a.size(); i++) {
                if (a[i] < a[i - 1]) return false;
            }
            return true;
        };

        // Keep performing operations until array becomes non-decreasing
        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

            // Find leftmost adjacent pair with minimum sum
            for (int i = 0; i < nums.size() - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // Merge the selected pair
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }

        return operations;
    }
};
