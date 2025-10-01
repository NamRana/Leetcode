class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }

        //Store frequencies
        vector<int> counts;
        for(auto &p:freq){
            counts.push_back(p.second);
        }

        //if already <=k distinct char
        if((int)counts.size()<=k)return 0;

        //sort frequencies ascending
        sort(counts.begin(),counts.end());

        int deletions=0;
        int distinct=counts.size();

        //remove smallest freq characters until <=k remains
        for(int i=0;i<counts.size()&&distinct>k;i++){
            deletions+=counts[i];
            distinct--;
        }
        return deletions;
    }
};