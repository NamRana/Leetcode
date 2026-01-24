class Solution {
public:
    int longestSubsequence(string s, int k) {
        int value=0;
        int power=1;
        int count=0;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0')count++;
            else{
                if(value+power<=k){
                    value+=power;
                    count++;
                }
            }
            if(power<=k){
                power<<=1;
            }
        }
        return count;
    }
};