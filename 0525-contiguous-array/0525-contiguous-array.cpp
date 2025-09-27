class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> prefixIndex;
        prefixIndex[0]=-1;
        int sum=0;
        int maxLen=0;

        for(int i=0;i<nums.size();i++){
            //treat 0 as -1
            if(nums[i]==0)sum+=-1;
            else sum+=1;
        

        //checking if this prefix sum has been seen before
        if(prefixIndex.count(sum)){
            maxLen=max(maxLen,i-prefixIndex[sum]);
        }else{
            prefixIndex[sum]=i;
        }
        }
        return maxLen;
    }
};