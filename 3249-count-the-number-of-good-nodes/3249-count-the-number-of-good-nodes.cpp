#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    int goodNodes = 0;

    int dfs(int node, int parent) {
        int subtreeSize = 1;  // count this node
        unordered_set<int> childSizes;

        for (int nei : adj[node]) {
            if (nei == parent) continue;

            int childSubtree = dfs(nei, node);
            subtreeSize += childSubtree;
            childSizes.insert(childSubtree);
        }

        // If all child subtree sizes are same (or no children)
        if (childSizes.size() <= 1) {
            goodNodes++;
        }

        return subtreeSize;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adj.resize(n);

        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return goodNodes;
    }
};
