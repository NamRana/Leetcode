class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> maxDP(m, vector<long long>(n, 0));
        vector<vector<long long>> minDP(m, vector<long long>(n, 0));

        // Initialization
        maxDP[0][0] = minDP[0][0] = grid[0][0];

        // First row
        for (int j = 1; j < n; j++) {
            maxDP[0][j] = minDP[0][j] = maxDP[0][j - 1] * grid[0][j];
        }

        // First column
        for (int i = 1; i < m; i++) {
            maxDP[i][0] = minDP[i][0] = maxDP[i - 1][0] * grid[i][0];
        }

        // DP transition
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];

                long long a = maxDP[i - 1][j] * val;
                long long b = minDP[i - 1][j] * val;
                long long c = maxDP[i][j - 1] * val;
                long long d = minDP[i][j - 1] * val;

                maxDP[i][j] = max({a, b, c, d});
                minDP[i][j] = min({a, b, c, d});
            }
        }

        long long ans = maxDP[m - 1][n - 1];
        return ans < 0 ? -1 : ans % MOD;
    }
};
