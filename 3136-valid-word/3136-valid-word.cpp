class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        string vowels="aeiouAEIOU";
        auto isVowel=[&](char c) {return vowels.find(c)!=string::npos;};
        bool hasvowel=false, hasConsonant=false;

        for(char c: word){
            if(!isdigit(c)&&!isalpha(c))return false;

            if(isalpha(c)){
                if(isVowel(c)){
                    hasvowel=true;
                }
                else{
                    hasConsonant=true;
                }
            }
        }
        return hasvowel&&hasConsonant;
    }
};