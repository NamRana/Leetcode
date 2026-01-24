class Solution {
public:
    long long ans = LLONG_MIN;

    void dfs(int i, vector<int>& nums, long long product, bool taken) {
        if (i == nums.size()) {
            if (taken) ans = max(ans, product);
            return;
        }

        // take current element
        dfs(i + 1, nums, product * nums[i], true);

        // skip current element
        dfs(i + 1, nums, product, taken);
    }

    long long maxStrength(vector<int>& nums) {
        dfs(0, nums, 1, false);
        return ans;
    }
};
