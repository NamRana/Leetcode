class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen,left,ans={},0,0
        for i,c in enumerate(s):
            if c in seen:
                left=max(left,seen[c]+1)
            seen[c]=i
            ans=max(ans,i-left+1)
        return ans