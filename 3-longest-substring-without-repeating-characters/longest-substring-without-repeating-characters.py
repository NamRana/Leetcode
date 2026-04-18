from functools import reduce


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        return reduce(lambda acc, ic: (max(acc[0], ic[0] - max(acc[1], acc[2].get(ic[1], -1) + 1) + 1), max(acc[1], acc[2].get(ic[1], -1) + 1), {**acc[2], ic[1]: ic[0]}), enumerate(s), (0, 0, {}))[0]
