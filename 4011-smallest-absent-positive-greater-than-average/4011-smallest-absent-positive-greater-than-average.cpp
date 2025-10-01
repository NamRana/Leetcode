class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size();
        double sum=0;
        unordered_set<int> s;

        //calculting sum and adding elements to set
        for(int num:nums){
            sum+=num;
            s.insert(num);
        }

        //calculating average
        double avg=double(sum)/n;

        //smallest integer strictly greater than average
        int result=max(1,(int)floor(avg)+1);

        while(s.count(result)){
            result++;
        }
        return result;
    }
};