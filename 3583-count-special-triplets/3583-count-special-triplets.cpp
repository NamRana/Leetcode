class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD=1e9+7;
        int n=nums.size();
        vector<long long> leftFreq(200005,0),rightFreq(200005,0);

        for(int x:nums)rightFreq[x]++;
        long long ans=0;

        for(int j=0;j<n;j++){
            int val=nums[j];
            rightFreq[val]--;

            long long target=(long long)val*2;
            if(target<=200000){
                long long leftCount=leftFreq[target];
                long long rightCount=rightFreq[target];
                ans=(ans+(leftCount*rightCount)%MOD)%MOD;
            }
            leftFreq[val]++;
        }
        return ans;
    }
};