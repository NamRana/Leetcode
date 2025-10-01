class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> freq;
        for(auto c:target){
            freq[c]++;
        }

        for(auto d:arr){
            --freq[d];
            if(freq[d]<0)return false;
        }
        return true;
    }
};