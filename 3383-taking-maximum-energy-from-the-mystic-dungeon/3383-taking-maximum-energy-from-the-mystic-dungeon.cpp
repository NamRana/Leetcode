class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
         int n = energy.size();
    vector<int> dp(n, 0);  // dp[i] = max energy starting from i
    int ans = INT_MIN;     // to store the final maximum

    // Traverse backwards because dp[i] depends on dp[i + k]
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = energy[i];
        if (i + k < n) {
            dp[i] += dp[i + k]; // Add future reachable energy
        }
        ans = max(ans, dp[i]);  // Track the best result
    }

    return ans;
    }
};