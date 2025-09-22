class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num:nums){
            freq[num]++;
        }
        int maxlen=0;
        for(auto it:freq){
            int num=it.first;
            if(freq.find(num+1)!=freq.end()){
                maxlen=max(maxlen,freq[num]+freq[num+1]);
            }
        }
        return maxlen;
    }
};