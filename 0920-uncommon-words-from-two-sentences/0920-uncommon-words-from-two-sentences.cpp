class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> wordCount;

        //splitting s1 into words and counting
        stringstream ss1(s1);
        string word;
        while(ss1>>word){
            wordCount[word]++;
        }

        //splitting s2 into words anc counting
        stringstream ss2(s2);
        while(ss2>>word){
            wordCount[word]++;
        }

        //collect words with frequency=1

        vector<string> result;
        for(auto& [w,count]:wordCount){
            if(count==1){
                result.push_back(w);
            }
        }
        return result;
    }
};