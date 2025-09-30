class Solution {
public:
    int maximumLengthSubstring(string s) {
                int n = s.size();
        vector<int> freq(26, 0);  // frequency of each character
        int left = 0;             // left pointer of window
        int maxLen = 0;           // store maximum length

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;  // add current character to window

            // shrink window if any character occurs more than 2
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            // update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};