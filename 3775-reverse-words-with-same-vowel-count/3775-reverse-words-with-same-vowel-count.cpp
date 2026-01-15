class Solution {
public:
    //Helper function
    int countVowels(const string &word){
        int count=0;
        for(char c: word){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                count++;
            }
        }
        return count;
    }
    string reverseWords(string s) {
        vector<string> words;
        string current="";

        //split string into words
        for(char c:s){
            if(c==' '){
                words.push_back(current);
                current.clear();
            }else{
                current+=c;
            }
        }
        words.push_back(current);

        int baseVowelCount=countVowels(words[0]);

        for(int i=1;i<words.size();i++){
            if(countVowels(words[i])==baseVowelCount){
                reverse(words[i].begin(),words[i].end());
            }
        }

        string result=words[0];
        for(int i=1;i<words.size();i++){
            result+=" "+words[i];
        }
        return result;
    }
};