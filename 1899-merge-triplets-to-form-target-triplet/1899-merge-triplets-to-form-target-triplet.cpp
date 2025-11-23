class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a=false, b=false, c=false;

        //target values
        int x=target[0];
        int y=target[1];
        int z=target[2];

        for(auto &t: triplets){
            if(t[0]>x || t[1]>y || t[2]>z){
                continue;
            }

            if(t[0]==x)a=true;
            if(t[1]==y)b=true;

            if(t[2]==z)c=true;
        }
        return a&&b&&c;
    }
};