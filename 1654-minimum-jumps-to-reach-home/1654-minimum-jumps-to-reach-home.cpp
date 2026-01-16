class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());

        // Upper bound to prevent infinite forward jumps
        int maxLimit = max(x, *max_element(forbidden.begin(), forbidden.end())) + a + b;

        // visited[pos][0] -> last jump was forward
        // visited[pos][1] -> last jump was backward
        vector<vector<bool>> visited(maxLimit + 1, vector<bool>(2, false));

        queue<pair<pair<int, int>, int>> q;
        // ((position, last_jump_backward), steps)
        q.push({{0, 0}, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int pos = curr.first.first;
            int back = curr.first.second;
            int steps = curr.second;

            if (pos == x) return steps;

            // Forward jump
            int forward = pos + a;
            if (forward <= maxLimit &&
                forbiddenSet.count(forward) == 0 &&
                !visited[forward][0]) {

                visited[forward][0] = true;
                q.push({{forward, 0}, steps + 1});
            }

            // Backward jump (only if last jump was NOT backward)
            if (back == 0) {
                int backward = pos - b;
                if (backward >= 0 &&
                    forbiddenSet.count(backward) == 0 &&
                    !visited[backward][1]) {

                    visited[backward][1] = true;
                    q.push({{backward, 1}, steps + 1});
                }
            }
        }

        return -1;
    }
};
