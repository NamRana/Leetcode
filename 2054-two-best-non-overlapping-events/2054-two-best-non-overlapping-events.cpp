class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        // Sort events by start time
        sort(events.begin(), events.end());

        // suffixMax[i] = max value from events[i] to events[n-1]
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        // For each event, try to pair it with the best next valid event
        for (int i = 0; i < n; i++) {
            int currValue = events[i][2];
            int nextStart = events[i][1] + 1;

            // Binary search for first event with start >= nextStart
            int l = i + 1, r = n - 1;
            int idx = n;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (events[mid][0] >= nextStart) {
                    idx = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            // If valid next event exists, add its best possible value
            if (idx < n) {
                currValue += suffixMax[idx];
            }

            ans = max(ans, currValue);
        }

        return ans;
    }
};
