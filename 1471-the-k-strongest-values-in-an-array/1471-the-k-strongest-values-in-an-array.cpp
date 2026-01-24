class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());  // Step 1: sort array
        int n = arr.size();
        int m = arr[(n - 1) / 2];      // Step 2: find center

        // Step 3: custom sort by strength
        sort(arr.begin(), arr.end(), [m](int a, int b) {
            int diffA = abs(a - m);
            int diffB = abs(b - m);
            if (diffA == diffB)
                return a > b;           // tie-breaker: bigger number first
            return diffA > diffB;      // stronger = bigger difference
        });

        // Step 4: take first k elements
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
};
