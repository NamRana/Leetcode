class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> freq;
        int count=0;

        for(auto &d: dominoes){
            int a=min(d[0],d[1]);
            int b=max(d[0],d[1]);

            //storing as 2 digit number
            int key=a*10+b;

            count+=freq[key];

            freq[key]++;
        }
        return count;
    }
};