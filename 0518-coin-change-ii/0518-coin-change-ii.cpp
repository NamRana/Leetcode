class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1,0);
        dp[0]=1;

        for(int coin:coins){
            //updating dp array for all amounts which is greater than coin
            for(int j=coin;j<=amount;j++){
                dp[j]+=dp[j-coin];
            }
        }
        return (int)dp[amount];
    }
};