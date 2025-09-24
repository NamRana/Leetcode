class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums,0,subset,res);
        return res;
    }

    void backtrack(vector<int> &nums,int index,vector<int> &subset,vector<vector<int>>&res){
        res.push_back(subset); //adding current subset

        for(int i=index;i<nums.size();i++){
            //skip duplicates, using only the first occurences at the recursion level
            if(i>index && nums[i]==nums[i-1])continue;

            subset.push_back(nums[i]);  //incuding the nums[i]
            backtrack(nums,i+1,subset,res); //recurse for next element
            subset.pop_back(); // remove last element        
            }
    }
};