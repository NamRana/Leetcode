class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        visited[x][y] = true;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // boundary check
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            // must have same character
            if (grid[nx][ny] != grid[x][y])
                continue;

            // don't go back to parent
            if (nx == px && ny == py)
                continue;

            // visited & not parent = cycle
            if (visited[nx][ny])
                return true;

            // explore deeper
            if (dfs(nx, ny, x, y, grid))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }
        return false;
    }
};
