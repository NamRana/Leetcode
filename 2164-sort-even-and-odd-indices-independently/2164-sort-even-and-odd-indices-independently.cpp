class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        vector<int> even;  // Stores values from even indices
        vector<int> odd;   // Stores values from odd indices

        // Step 1: Separate values based on index parity
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                even.push_back(nums[i]); // even index
            else
                odd.push_back(nums[i]);  // odd index
        }

        // Step 2: Sort even-index values in non-decreasing order
        sort(even.begin(), even.end());

        // Step 3: Sort odd-index values in non-increasing order
        sort(odd.begin(), odd.end(), greater<int>());

        // Step 4: Put values back into nums
        int e = 0, o = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                nums[i] = even[e++]; // place next even value
            else
                nums[i] = odd[o++];  // place next odd value
        }

        return nums;
    }
};
