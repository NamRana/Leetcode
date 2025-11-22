class Solution {
public:
     int solve(int n, vector<int>& memo) {
        if (n == 1 || n == 2) return n;

        // If already computed → return stored value
        if (memo[n] != -1) return memo[n];

        // Store & return result
        memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};