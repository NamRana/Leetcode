class Solution {
public:
    int removePalindromeSub(string s) {
        //checking if s is a palindrome
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                //not palindrome--> need 2 steps
                return 2;
            }
            i++;j--;
        }
        return 1;
    }
};