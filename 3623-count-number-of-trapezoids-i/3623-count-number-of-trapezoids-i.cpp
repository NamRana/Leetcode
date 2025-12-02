class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> pointNum;
        const int mod=1e9+7;
        long long ans=0,sum=0;

        for(auto &point: points){
            int y=point[1];
            pointNum[y]++;
        }

        for(auto &[_,pNum]:pointNum){
            long long edge=(long long)pNum*(pNum-1)/2;
            ans+=edge*sum;
            sum+=edge;
        
        }
        return ans%mod;
    }
};