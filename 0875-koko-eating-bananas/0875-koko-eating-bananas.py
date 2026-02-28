from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)
        
        while left < right:
            mid = (left + right) // 2
            
            # Calculate total hours needed at speed mid
            total_hours = 0
            for pile in piles:
                total_hours += math.ceil(pile / mid)
            
            # If can finish in h hours, try smaller speed
            if total_hours <= h:
                right = mid
            else:
                left = mid + 1
        
        return left