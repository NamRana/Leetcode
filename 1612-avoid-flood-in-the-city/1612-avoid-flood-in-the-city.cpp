class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> full;  // lake -> last rain day
    set<int> dryDays;              // indices of dry days
    vector<int> ans(rains.size(), -1);

    for (int i = 0; i < rains.size(); ++i) {
        int lake = rains[i];
        if (lake > 0) {
            if (full.count(lake)) {
                // Need to dry this lake before today
                auto it = dryDays.lower_bound(full[lake]);
                if (it == dryDays.end()) return {}; // No available dry day
                ans[*it] = lake;     // Dry this lake
                dryDays.erase(it);
            }
            full[lake] = i; // Update last rain day
            ans[i] = -1;    // Raining day
        } else {
            dryDays.insert(i); // Mark this as a dry day
            ans[i] = 1;        // Default dry any lake
        }
    }

    return ans;
    }
};