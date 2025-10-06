class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {elevation, row, col}
        pq.push({grid[0][0], 0, 0});
        
        int maxElevation = 0;
        vector<int> dir = {1, 0, -1, 0, 1}; // for 4 directions
        
        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int elevation = cell[0];
            int x = cell[1];
            int y = cell[2];
            
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            // Update max elevation so far
            maxElevation = max(maxElevation, elevation);
            
            // If we reached the destination
            if (x == n - 1 && y == n - 1)
                return maxElevation;
            
            // Explore 4-directionally adjacent cells
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        
        return -1; // should never reach here
    }
};