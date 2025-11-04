class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int remaning=target-nums[i];
            if(mp.find(remaning)!=mp.end()){
            return {mp[remaning],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};