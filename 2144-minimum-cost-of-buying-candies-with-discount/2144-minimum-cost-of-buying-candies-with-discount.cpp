class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<>());
        int sum=0;
        for(int i=0;i<cost.size();i++){
            if((i+1)%3!=0){
               sum+=cost[i]; 
            }
        }
        return sum;
    }
};