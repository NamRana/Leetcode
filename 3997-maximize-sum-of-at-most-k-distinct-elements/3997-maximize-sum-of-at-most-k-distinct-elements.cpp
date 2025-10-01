class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> result(st.begin(),st.end());

       sort(result.rbegin(),result.rend());

       if(result.size()>k){
        result.resize(k);
       }
        return result;
    }
};