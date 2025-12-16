class Solution {
public:

    int expand(string &s,int i,int j){
        while(i>=0&&j<s.size()&&s[i]==s[j]){
            i--;j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int start=0;int end=0;

        for(int i=0;i<s.size();i++){
            int len1=expand(s,i,i);//odd length palindrome

            int len2=expand(s,i,i+1);//even length palindrome

            int len=max(len1,len2);

            if(len>end-start+1){
                start=i-(len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};