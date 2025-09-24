class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());
        int largest=arr.back().first;
        int largestIndex=arr.back().second;

        int secondLargest=-1;
        if(arr.size()>1){
            secondLargest=arr[arr.size()-2].first;
        }

        if(largest>=2*secondLargest){
            return largestIndex;
        }

        return -1;
    }
};