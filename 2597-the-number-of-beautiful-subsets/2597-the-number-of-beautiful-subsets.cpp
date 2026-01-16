class Solution {
public:
    int ans=0;//stores total count of beautiful subsets

    unordered_map<int,int> freq;

    void dfs(int idx,vector<int>&nums,int k){
        if(idx==nums.size()){
            if(!freq.empty())ans++;
            return;
        }

        dfs(idx+1,nums,k);
        int val=nums[idx];

        if(freq[val-k]==0 && freq[val+k]==0){
            freq[val]++;
            dfs(idx+1,nums,k);
            freq[val]--;

            if(freq[val]==0)freq.erase(val);
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        dfs(0,nums,k);
        return ans;
    }
};