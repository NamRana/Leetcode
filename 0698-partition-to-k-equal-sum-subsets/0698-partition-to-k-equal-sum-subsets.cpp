class Solution {
public:
    int n;
    int target;
    unordered_map<int, bool> memo;

    bool dfs(vector<int>& nums, int k, int currSum, int mask) {

        // If only one subset left, it's guaranteed to work
        if (k == 1) return true;

        // If current subset is completed, start next subset
        if (currSum == target)
            return dfs(nums, k - 1, 0, mask);

        // If this state was already computed
        if (memo.count(mask)) return memo[mask];

        for (int i = 0; i < n; i++) {
            // If nums[i] is not used yet
            if (!(mask & (1 << i))) {
                if (currSum + nums[i] > target) continue;

                // Try including nums[i]
                if (dfs(nums, k, currSum + nums[i], mask | (1 << i)))
                    return memo[mask] = true;
            }
        }

        return memo[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % k != 0) return false;

        target = totalSum / k;
        n = nums.size();

        sort(nums.rbegin(), nums.rend());

        // Largest number cannot fit
        if (nums[0] > target) return false;

        return dfs(nums, k, 0, 0);
    }
};
