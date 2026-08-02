class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn=prices[0]
        mx=0

        for price in prices:
            mn=min(mn,price)
            profit=price-mn
            mx=max(profit,mx)
        return mx