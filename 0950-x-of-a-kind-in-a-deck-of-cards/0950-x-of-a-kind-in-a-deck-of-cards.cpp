class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> freq;

        //counting frequencies for each numeber
        for(int n:deck){
            freq[n]++;
        }

        ///finding GCD for all frequencies
        int g=0;
        for(auto &p:freq){
            g=gcd(g,p.second);
        }
        return g>=2;
    }
};