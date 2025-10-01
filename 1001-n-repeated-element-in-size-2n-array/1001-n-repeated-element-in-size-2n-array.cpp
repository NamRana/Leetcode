class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto num:nums){
            map[num]++;
        
        if(map[num]>1){
            return num;
        }
        }
        return -1;
    }
};