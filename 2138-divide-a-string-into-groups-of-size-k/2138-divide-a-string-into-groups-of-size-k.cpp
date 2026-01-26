class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for(int i=0;i<s.size();i+=k){
            string group=s.substr(i,k);

            if(group.length()<k){
                group+=string(k-group.length(),fill);
            }
            ans.push_back(group);
        }
        return ans;
    }
};