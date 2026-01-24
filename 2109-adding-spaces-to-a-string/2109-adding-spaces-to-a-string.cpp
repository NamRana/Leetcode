class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int j = 0;  // pointer for spaces

        for (int i = 0; i < s.size(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                res += ' ';  // insert space before character
                j++;         // move to next index in spaces
            }
            res += s[i];     // add the character
        }

        return res;
    }
};
