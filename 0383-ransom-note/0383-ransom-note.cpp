class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //creating frequency araay for 26 lower case letters
        vector<int> freq(26,0);

        //couting letters in magazine
        for(char c: magazine){
            freq[c-'a']++;
        }

        //checking ransomenote requirements
        for(char c: ransomNote){
            freq[c-'a']--;

            if(freq[c-'a']<0){
                return false;
            }
        }
        return true;
    }
};