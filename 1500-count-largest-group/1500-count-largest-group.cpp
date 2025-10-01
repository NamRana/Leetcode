class Solution {
public:
    // Helper function to calculate digit sum
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;  // add last digit
            num /= 10;        // remove last digit
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        unordered_map<int, int> freq; // digitSum -> count of numbers
        int maxSize = 0;

        // Step 1: Fill groups
        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            freq[sum]++;
            maxSize = max(maxSize, freq[sum]); // update largest size
        }

        // Step 2: Count how many groups reached max size
        int count = 0;
        for (auto &p : freq) {
            if (p.second == maxSize) count++;
        }

        return count;
    }
};