class Solution {
public:
    int totalNumbers(vector<int>& digits) {
             vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        unordered_set<int> uniqueNums;

        // Try all 3-digit numbers
        for (int a = 1; a <= 9; a++) {          // hundreds (no leading 0)
            if (freq[a] == 0) continue;
            for (int b = 0; b <= 9; b++) {      // tens
                if (freq[b] == 0) continue;
                for (int c = 0; c <= 9; c += 2) {  // ones (must be even)
                    if (freq[c] == 0) continue;

                    // Count usage
                    vector<int> used(10, 0);
                    used[a]++; used[b]++; used[c]++;

                    // Check if usage <= available
                    bool valid = true;
                    for (int d = 0; d <= 9; d++) {
                        if (used[d] > freq[d]) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) {
                        int num = 100*a + 10*b + c;
                        uniqueNums.insert(num);
                    }
                }
            }
        }

        return uniqueNums.size();
    }
};