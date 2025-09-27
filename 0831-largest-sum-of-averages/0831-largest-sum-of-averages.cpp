class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();

        //computing prefix sums
        vector<double> prefix(n+1,0.0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        //DP table
        vector<vector<double>> dp(n+1, vector<double>(k+1,0.0));

        //base case: 1 partition -> average of first i elements

        for(int i=1;i<=n;i++){
            dp[i][1]=prefix[i]/i;
        }

        //Filling DP table
        for(int p=2;p<=k;p++){  //number of partitions
            for(int i=p;i<=n;i++){ // total elements
                for(int j=p-1;j<i;j++){
                    dp[i][p]=max(dp[i][p],dp[j][p-1]+(prefix[i]-prefix[j])/(i-j));
                }
            }
        }
        return dp[n][k];
    }
};