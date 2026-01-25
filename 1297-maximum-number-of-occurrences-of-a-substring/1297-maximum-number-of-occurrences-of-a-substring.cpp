class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        vector<int> count(26, 0);

        int unique = 0;
        int left = 0;
        int n = s.size();
        int ans = 0;

        for (int right = 0; right < n; right++) {
            // add right character
            if (++count[s[right] - 'a'] == 1)
                unique++;

            // shrink window if size exceeds minSize
            if (right - left + 1 > minSize) {
                if (--count[s[left] - 'a'] == 0)
                    unique--;
                left++;
            }

            // check valid window
            if (right - left + 1 == minSize && unique <= maxLetters) {
                string sub = s.substr(left, minSize);
                ans = max(ans, ++freq[sub]);
            }
        }

        return ans;
    }
};
