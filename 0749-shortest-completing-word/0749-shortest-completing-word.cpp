class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> lpCount(26,0);

        //Count letters in the lincensePlate
        for(char c: licensePlate){
            if(isalpha(c)){
                lpCount[tolower(c)-'a']++;
            }
        }

        string ans=""; //store shortest completing word

        //checing each word
        for(string &word:words){
            vector<int> wordCount(26,0);
            for(char c:word){
                wordCount[c-'a']++;
            }

            bool valid=true;
            for(int i=0;i<26;i++){
                if(wordCount[i]<lpCount[i]){
                    valid=false;
                    break;
                }
            }

            if(valid && (ans.empty()|| word.size()<ans.size())){
                ans=word;
            }
        }
        return ans;
    }
};