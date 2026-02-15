class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left=0 #left pointer of window
        char_set=set() #to store unique characters
        max_length=0

        #expanding window using right pointer
        for right in range(len(s)):

            while s[right] in char_set:
                char_set.remove(s[left])
                left+=1
            
            char_set.add(s[right])

            max_length=max(max_length,right-left+1)
        return max_length
        