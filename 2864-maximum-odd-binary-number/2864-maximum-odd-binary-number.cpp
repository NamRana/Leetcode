class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0;
        int n=s.length();

        for(char c:s){
            if(c=='1'){
                one++;
            }
        }

        one--;

        string ans="";

        ans.append(one,'1');
        ans.append(n-one-1,'0');

        ans.push_back('1');

        return ans;
    }
};