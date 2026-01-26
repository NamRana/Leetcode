class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for(int i=0;i<s.size();i+=k){
            string group=s.substr(i,k);
            if(group.size()<k){
                group+=string(k-group.size(),fill);
            }

            ans.push_back(group);
        }
        return ans;
    }
};