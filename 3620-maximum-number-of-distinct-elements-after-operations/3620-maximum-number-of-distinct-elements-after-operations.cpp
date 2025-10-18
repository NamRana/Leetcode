class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        vector<pair<long long, long long>> intervals;
        for (long long x : nums)
            intervals.push_back({x - k, x + k});

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second < b.second; // sort by end point
        });

        long long lastUsed = LLONG_MIN;
        int count = 0;

        for (auto &[start, end] : intervals) {
            // choose smallest number >= start and > lastUsed
            long long choose = max(start, lastUsed + 1);
            if (choose <= end) {
                count++;
                lastUsed = choose; // mark it used
            }
        }
        return count;
    }
};