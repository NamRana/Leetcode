class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;

        for (string word : words) {

            unordered_map<char, char> mp; // pattern → word mapping
            unordered_set<char> used;     // to ensure bijection
            bool valid = true;

            for (int i = 0; i < word.size(); i++) {
                char p = pattern[i];
                char w = word[i];

                // If pattern character not mapped yet
                if (mp.find(p) == mp.end()) {

                    // If word character already used → invalid
                    if (used.count(w)) {
                        valid = false;
                        break;
                    }

                    mp[p] = w;
                    used.insert(w);
                }
                // If already mapped, check consistency
                else {
                    if (mp[p] != w) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) result.push_back(word);
        }

        return result;
    }
};
