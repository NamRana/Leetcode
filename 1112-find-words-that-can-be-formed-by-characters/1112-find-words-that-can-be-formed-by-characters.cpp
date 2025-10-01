class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int total=0;
        int charFreq[26]={0};

        //counting frequency of char
        for(char c: chars){
            charFreq[c-'a']++;
        }

        //checking each word
        for(string word:words){
            int wordFreq[26]={0};
            for(char c:word){
                wordFreq[c-'a']++;
            }

            bool canForm=true;
            for(int i=0;i<26;i++){
                if(wordFreq[i]>charFreq[i]){
                    canForm=false;
                    break;
                }
            }

            if(canForm){
                total+=word.length();
            }
        }
        return total;
    }
};