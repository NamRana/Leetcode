class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        // Custom sort: larger numbers first
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.length() != b.length())
                return a.length() > b.length();  // longer string = larger number
            return a > b;                        // same length → lexicographical
        });

        return nums[k - 1];
    }
};
