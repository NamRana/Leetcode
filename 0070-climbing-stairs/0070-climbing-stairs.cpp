class Solution {
public:
    int solve(int n, vector<int>& mem){
        if(n==1 || n==2) return n;
        if(mem[n]!=-1)return mem[n];
        mem[n]=solve(n-1,mem)+solve(n-2,mem);
        return mem[n];

    }
    int climbStairs(int n) {
        vector<int> mem(n+1,-1);

        return solve(n,mem);
    }
};