class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        //fliiping negative numbers
        for(int i=0;i<nums.size()&&k>0;i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
                k--;
            }
        }
        //sort again to get smallest number
        sort(nums.begin(),nums.end());

        //if k is odd, flip smallest number
        if(k%2==1){
            nums[0]=-nums[0];
        }

        //calculate sum
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        return sum;
    }
};