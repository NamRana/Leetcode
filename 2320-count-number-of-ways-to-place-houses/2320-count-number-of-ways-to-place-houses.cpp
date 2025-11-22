class Solution {
public:
 const long long MOD = 1000000007;

    long long solve(int n, vector<int>& memo){
        if(n==0)return 1;
        if(n==1)return 2;
        if(memo[n]!=-1)return memo[n];

        long long res=(solve(n-1,memo)+solve(n-2,memo))%MOD;
        memo[n]=res;
        return res;
    }
    int countHousePlacements(int n) {
        vector<int> memo(n+1,-1);
        long long ans=solve(n,memo);

        long long result=(ans*ans)%MOD;

        return (int)result;
    }
};