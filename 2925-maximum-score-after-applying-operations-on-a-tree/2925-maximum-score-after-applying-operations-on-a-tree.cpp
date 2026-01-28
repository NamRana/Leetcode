class Solution {
public:
    vector<vector<int>> adj;
    vector<long long> values;

    long long dfs(int u, int parent) {
        long long sumChildren = 0;
        bool isLeaf = true;

        for (int v : adj[u]) {
            if (v == parent) continue;
            isLeaf = false;
            sumChildren += dfs(v, u);
        }

        if (isLeaf) {
            // Leaf must keep itself
            return values[u];
        }

        // Either keep this node OR rely on children
        return min(values[u], sumChildren);
    }

    long long maximumScoreAfterOperations(
        vector<vector<int>>& edges,
        vector<int>& vals
    ) {
        int n = vals.size();
        adj.resize(n);
        values.assign(vals.begin(), vals.end());

        long long total = 0;
        for (long long v : values) total += v;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long mustKeep = dfs(0, -1);
        return total - mustKeep;
    }
};
