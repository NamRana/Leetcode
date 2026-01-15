class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        // 26 buckets for characters 'a' to 'z'
        // Each bucket stores:
        //   (index of word in words[], current character index in that word)
        vector<vector<pair<int,int>>> buckets(26);

        int count = 0; // counts valid subsequences

        // ------------------------------------------------
        // STEP 1: Initialize buckets with first character
        // ------------------------------------------------
        for (int i = 0; i < words.size(); i++) {
            // Place each word in bucket of its first character
            char firstChar = words[i][0];
            buckets[firstChar - 'a'].push_back({i, 0});
        }

        // ---------------------------------------------
        // STEP 2: Traverse main string `s`
        // ---------------------------------------------
        for (char ch : s) {

            // Bucket index for current character
            int bucketIndex = ch - 'a';

            // Extract all words waiting for this character
            // IMPORTANT: copy bucket, then clear it
            auto currentBucket = buckets[bucketIndex];
            buckets[bucketIndex].clear();

            // Process each waiting word
            for (auto &p : currentBucket) {

                int wordIndex = p.first;      // which word
                int charIndex = p.second + 1; // move to next character

                // If entire word is matched
                if (charIndex == words[wordIndex].size()) {
                    count++;  // valid subsequence found
                }
                else {
                    // Otherwise, push word to bucket of next needed character
                    char nextChar = words[wordIndex][charIndex];
                    buckets[nextChar - 'a'].push_back({wordIndex, charIndex});
                }
            }
        }

        return count;
    }
};
