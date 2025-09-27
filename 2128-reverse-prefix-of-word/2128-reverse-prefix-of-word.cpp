class Solution {
public:
    string reversePrefix(string word, char ch) {
        //finding first occurence for ch
        int idx=word.find(ch);

        //if not found, return original string
        if(idx==string::npos)return word;

        //reverse prefix [0..idx]
        reverse(word.begin(),word.begin()+idx+1);

        return word;
    }
};