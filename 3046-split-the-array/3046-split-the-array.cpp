class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
            
            // If any number appears more than twice, impossible
            if (freq[num] > 2)
                return false;
        }

        // All numbers appear at most twice
        return true;
    }
};
