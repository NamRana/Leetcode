class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;
        string vowels = "aeiou";
        
        auto isVowel = [&](char c) {
            return vowels.find(c) != string::npos;
        };
        
        for (int i = 0; i < n; i++) {
            if (!isVowel(word[i])) continue; // substring must start with vowel
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                if (!isVowel(word[j])) break; // stop if consonant appears
                st.insert(word[j]);
                if (st.size() == 5) count++;
            }
        }
        
        return count;
    }
};
