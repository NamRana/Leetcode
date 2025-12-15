class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 1;   // At least one single-day period exists
        long long len = 1;      // Length of current smooth descent sequence

        for (int i = 1; i < prices.size(); i++) {
            // Check if current price is exactly 1 less than previous price
            if (prices[i] == prices[i - 1] - 1) {
                len++;          // Extend the smooth descent
            } else {
                len = 1;        // Reset sequence
            }
            result += len;      // Add number of new subarrays ending here
        }

        return result;
    }
};
