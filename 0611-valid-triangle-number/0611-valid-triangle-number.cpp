class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;

        //fix the largest side at index k
        for(int k=n-1;k>=2;k--){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    //all pairs between i and j-1 with j are valid
                    count+=(j-i);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return count;
    }
};