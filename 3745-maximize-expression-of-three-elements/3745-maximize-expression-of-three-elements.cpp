class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        return nums[0]+nums[1]-nums.back();
    }
};