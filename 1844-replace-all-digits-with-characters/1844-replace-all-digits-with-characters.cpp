class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.length(); i += 2) {
            int shift = s[i] - '0';          // convert digit to number
            s[i] = s[i - 1] + shift;         // shift character
        }
        return s;
    }
};
