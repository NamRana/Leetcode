class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int counta=0,countb=0;

        for(int i=0;i<n/2;i++){
            if(isVowel(s[i]))counta++;
            if(isVowel(s[i+n/2]))countb++;
        }
        return counta==countb;
    }
};