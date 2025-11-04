class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int start = 0; start <= n - k; start++) {
            unordered_map<int, int> freq;

            // Count frequency in the current window
            for (int i = start; i < start + k; i++) {
                freq[nums[i]]++;
            }

            // Store (frequency, value) pairs
            vector<pair<int, int>> list;
            for (auto &p : freq) {
                list.push_back({p.second, p.first});
            }

            // Sort by highest frequency first, highest value second
            sort(list.begin(), list.end(), [](auto &a, auto &b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });

            // Keep the top x elements
            unordered_set<int> keep;
            for (int i = 0; i < min(x, (int)list.size()); i++) {
                keep.insert(list[i].second);
            }

            // Sum only kept elements
            int sum = 0;
            for (int i = start; i < start + k; i++) {
                if (keep.count(nums[i])) {
                    sum += nums[i];
                }
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
