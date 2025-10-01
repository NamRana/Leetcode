class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;

        for(auto num:nums){
            if(seen.count(num)){
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};