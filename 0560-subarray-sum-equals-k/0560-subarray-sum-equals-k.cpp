class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0]=1;
        int sum=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i]; //updating running sum

            //check if (sum-k) exists in the map
            //if yes, it means that there are some subarrays ending at i with sum =k
            if(prefixCount.count(sum-k)){
                count+=prefixCount[sum-k];
            }
            prefixCount[sum]++;

        }
        return count;
    }
};