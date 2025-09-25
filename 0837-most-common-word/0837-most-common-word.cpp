class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(),banned.end()); //storing banned words
        unordered_map<string,int> wordCount; //making frequency map

        string word="";
        int n=paragraph.size();
        for(int i=0;i<=n;i++){
            char c=(i<n)?paragraph[i]:' ';
            if(isalpha(c)){
                word+=tolower(c);
            }
            else if(!word.empty()){
                if(bannedSet.find(word)==bannedSet.end()){
                    wordCount[word]++;
                }
                word="";
            }
        }

        string result="";
        int maxCount=0;
        for(auto &[w,count]:wordCount){
            if(count>maxCount){
                maxCount=count;
                result=w;
            }
        }
        return result;
    }
};