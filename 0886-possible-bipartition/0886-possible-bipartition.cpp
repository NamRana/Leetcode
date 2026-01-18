class Solution {
public:
    vector<vector<int>> graph;
    vector<int> color;

    bool dfs(int node, int c) {
        color[node] = c;

        for (int nei : graph[node]) {
            // If neighbor not colored, color with opposite
            if (color[nei] == 0) {
                if (!dfs(nei, -c))
                    return false;
            }
            // If neighbor has same color → conflict
            else if (color[nei] == c) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph.resize(n + 1);
        color.assign(n + 1, 0);

        // Build graph
        for (auto& d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        // Check all components
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                if (!dfs(i, 1))
                    return false;
            }
        }
        return true;
    }
};
