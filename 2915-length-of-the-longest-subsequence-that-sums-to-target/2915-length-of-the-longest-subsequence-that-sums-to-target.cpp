class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        dp[0]=0;

        for(int x:nums){
            for(int s=target;s>=x;s--){
                if(dp[s-x]!=-1){
                    dp[s]=max(dp[s],dp[s-x]+1);
                }
            }
        }
        return dp[target];
    }
};