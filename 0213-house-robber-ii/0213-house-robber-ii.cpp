class Solution {
public:
    int solve(int i,int end,vector<int>&nums,vector<int>&dp){
        if(i>end)return 0;

        if(dp[i]!=-1)return dp[i];

        int skip=solve(i+1,end,nums,dp);

        int rob=nums[i]+solve(i+2,end,nums,dp);

        return dp[i]=max(skip,rob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);

        //rob from 0->n-2
        vector<int> dp1(n,-1);
        int case1=solve(0,n-2,nums,dp1);

        //rob from 1->n-1
        vector<int> dp2(n,-1);
        int case2=solve(1,n-1,nums,dp2);

        return max(case1,case2);
    }
};