class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curr = 1;

        for (int num : arr) {
            if (curr < num) {
                int missing = num - curr;
                if (k <= missing) {
                    return curr + k - 1;
                }
                k -= missing;
            }
            curr = num + 1;
        }

        return curr + k - 1;
    }
};
