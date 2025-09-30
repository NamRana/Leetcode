class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size(),count=0,k=3;
        for(int i=0;i<=n-k;i++){
            unordered_set<char> st(s.begin()+i,s.begin()+i+k);
            if(st.size()==k)count++;
        }
        return count;
        }
};