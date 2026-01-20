class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            int res = -1;

            // Try all possible smaller values
            for (int x = 0; x < n; x++) {
                if ((x | (x + 1)) == n) {
                    res = x;
                    break;  // smallest found
                }
            }

            ans.push_back(res);
        }
        return ans;
    }
};
