class Solution {
public:
    int longestSubsequence(string s, int k) {
        int value = 0;
        int power = 1;
        int count = 0;
        
        // Traverse from right (LSB) to left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // zero is always safe
                count++;
            } else {
                // try including '1'
                if (value + power <= k) {
                    value += power;
                    count++;
                }
            }
            
            // prevent overflow & useless large powers
            if (power <= k)
                power <<= 1;
        }
        
        return count;
    }
};
