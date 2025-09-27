#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> mark(n, false); // mark k-distant indices

        // Step 1: Find all positions of key
        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                // Step 2: Mark indices i in [j-k, j+k]
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; i++) {
                    mark[i] = true;
                }
            }
        }

        // Step 3: Collect all marked indices
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (mark[i]) result.push_back(i);
        }

        return result;
    }
};
