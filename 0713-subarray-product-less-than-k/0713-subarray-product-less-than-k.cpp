class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0; //no subarray can have product<1
        int prod=1; //product of element in current window
        int left=0; //left pointer for window
        int count=0;//total valid subarray

        for(int right=0;right<nums.size();right++){
            prod*=nums[right];

            //shrink window from left while product>=k
            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            count+=(right-left+1);
        }
        return count;

    }
};