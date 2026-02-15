class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        
        rev=s[::-1]

        #Create new string for KMP processing
        new_string=s+"#"+rev

        lps=[0]*len(new_string)

        j=0 #length of previous longest prefix suffix

        for i in range(1,len(new_string)):
            while j>0 and new_string[i]!=new_string[j]:
                j=lps[j-1]

            if new_string[i]==new_string[j]:
                j+=1
                lps[i]=j

        #lps[-1] gives longest palindromic prefix length
        longest_p_prefix=lps[-1]

        #adding remaining reveresed suffix to front
        return rev[:len(s)-longest_p_prefix]+s