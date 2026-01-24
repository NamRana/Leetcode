class Solution {
public:
    bool isMatch(string query, string pattern) {
        int i = 0, j = 0;

        while (i < query.size()) {
            // if characters match, move both
            if (j < pattern.size() && query[i] == pattern[j]) {
                i++;
                j++;
            }
            else {
                // if uppercase mismatch → invalid
                if (isupper(query[i])) {
                    return false;
                }
                // lowercase can be skipped
                i++;
            }
        }

        // pattern must be fully matched
        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(isMatch(q, pattern));
        }
        return ans;
    }
};
