class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n=len(nums)

        dp=[-float('inf')]*n
        dp[0]=0

        for i in range(1,n):
            for j in range(i):

                if abs(nums[i]-nums[j])<=target:
                    dp[i]=max(dp[i],dp[j]+1)

        return dp[-1] if dp[-1]!=-float('inf') else -1
        