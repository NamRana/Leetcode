class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        int sum2=0;
        for(int n:nums){
            sum+=n;

            while(n>0){
                sum2+=n%10;
                n/=10;
            }
        }
    return abs(sum-sum2);
    }
};