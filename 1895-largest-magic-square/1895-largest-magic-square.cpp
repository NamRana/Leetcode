class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix sum for rows: row[i][j] = sum of grid[i][0..j-1]
        vector<vector<int>> row(m, vector<int>(n + 1, 0));

        // Prefix sum for columns: col[i][j] = sum of grid[0..i-1][j]
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        // Build prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        // Try squares from largest size to smallest
        for (int k = min(m, n); k >= 2; k--) {
            for (int r = 0; r + k <= m; r++) {
                for (int c = 0; c + k <= n; c++) {

                    // Target sum = first row of the square
                    int target = row[r][c + k] - row[r][c];
                    bool isMagic = true;

                    // Check all rows
                    for (int i = r; i < r + k; i++) {
                        if (row[i][c + k] - row[i][c] != target) {
                            isMagic = false;
                            break;
                        }
                    }

                    // Check all columns
                    for (int j = c; j < c + k && isMagic; j++) {
                        if (col[r + k][j] - col[r][j] != target) {
                            isMagic = false;
                            break;
                        }
                    }

                    // Check main diagonal
                    int diag1 = 0, diag2 = 0;
                    for (int i = 0; i < k; i++) {
                        diag1 += grid[r + i][c + i];
                        diag2 += grid[r + i][c + k - 1 - i];
                    }

                    if (isMagic && diag1 == target && diag2 == target)
                        return k;
                }
            }
        }

        // Every 1x1 grid is a magic square
        return 1;
    }
};
