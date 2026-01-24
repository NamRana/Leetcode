class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        // Step 1: Traverse the array
        for (int x : nums) {
            if (x < pivot) {
                less.push_back(x);      // smaller elements
            } else if (x == pivot) {
                equal.push_back(x);     // pivot elements
            } else {
                greater.push_back(x);   // larger elements
            }
        }

        // Step 2: Combine all parts
        vector<int> result;
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};
