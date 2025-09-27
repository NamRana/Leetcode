class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> freq1, freq2;

        //counting frequencies of each word in word1
        for(auto &w:words1){
            freq1[w]++;
        }

        //counting frequencies of each word in word2
        for(auto &w:words2){
            freq2[w]++;
        }

        int count =0;

        //checking words in freq1 map
        for(auto &p: freq1){
            string word=p.first;
            int f1=p.second;

            //must appear exactly once in both arrays
            if(f1==1&&freq2[word]==1)
            {
                count++;
            }
        }
        return count;
    }
};