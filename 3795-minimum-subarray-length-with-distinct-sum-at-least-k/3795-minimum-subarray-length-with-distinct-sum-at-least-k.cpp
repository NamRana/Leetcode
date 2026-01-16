#include<bits/stdc++.h>
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int l=0,r=0,size=100001;
        // l and r are the initial positions of the sliding window constraints 
        //size is the minimum size of the sub array that is possible
        int sum=0;
// sum is created to keep a check of the conditions
           int mpp[100001]={0};
        while(r<nums.size()){
            mpp[nums[r]]++;

            if (mpp[nums[r]]==1){
            sum=sum+nums[r];}
// this "if" condition is there to make sure that sum doesnt contains the duplicates. read the third point of "things to take care of"

            while (sum>=k){
                if (mpp[nums[l]]==1){
                    sum-=nums[l];
                }// to ensure the leftmost element which is being removed while shrinking is deleted from total sum only if its unique. else only its frequency is reduced.
                
                mpp[nums[l]]--;
                size=min(size,r-l+1);
                l++;
            }
// generally we shrink if the condition is false, but here use a different analogy, reason being we need to find the minimum size of the subarray possible, hence whenever the condition is met we need to check if there is a smaller subarray possible
           
                r++;
            
            
        }
        if (size!=100001){
        return size;}
        else return -1; // Because if size is not updated, we return -1
    }
};