class DSU {
public:
    vector<int> parent;

    // Initialize DSU with each node as its own parent
    DSU(int size) {
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
    }

    // Path-compressed find
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // Union by making parent of v's root = u's root
    void join(int u, int v) {
        parent[find(v)] = find(u);
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        // ✅ DSU will group all stations into connected components
        DSU dsu(c + 1);

        // Join all connected stations
        for (auto& p : connections) {
            dsu.join(p[0], p[1]);
        }

        // online[x] = whether station x is currently online
        vector<bool> online(c + 1, true);

        // offlineCounts[x] = how many times x has been turned offline (needed because
        // you may have multiple turn-offline queries for same station)
        vector<int> offlineCounts(c + 1, 0);

        // For each component root, store smallest online station
        // minimumOnlineStations[root] = smallest ID online in that component
        unordered_map<int, int> minimumOnlineStations;

        // ✅ First pass: forward scan to mark all offline stations
        for (auto& q : queries) {
            int op = q[0], x = q[1];
            if (op == 2) {         // type-2 = offline
                online[x] = false;
                offlineCounts[x]++; // count number of times it goes offline
            }
        }

        // ✅ Compute initial smallest online station per component
        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);

            // if root not mapped yet, mark none online (-1 means empty)
            if (!minimumOnlineStations.count(root)) {
                minimumOnlineStations[root] = -1;
            }

            int station = minimumOnlineStations[root];

            // Only consider stations still online
            if (online[i]) {
                if (station == -1 || station > i) {
                    minimumOnlineStations[root] = i; // keep smallest
                }
            }
        }

        vector<int> ans;

        // ✅ Now process queries in reverse
        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            int op = queries[i][0], x = queries[i][1];
            int root = dsu.find(x);
            int station = minimumOnlineStations[root];

            if (op == 1) {  // Query: who handles maintenance?
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    ans.push_back(station); // smallest online in same component
                }
            }

            if (op == 2) {  // In reverse, offline becomes "online again"
                if (offlineCounts[x] > 1) {
                    offlineCounts[x]--;
                } else {
                    offlineCounts[x] = 0;
                    online[x] = true;

                    // Update smallest online station for component
                    if (station == -1 || station > x) {
                        minimumOnlineStations[root] = x;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
