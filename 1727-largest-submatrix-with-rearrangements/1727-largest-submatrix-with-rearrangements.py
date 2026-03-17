class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        if not matrix:
            return 0
        heights = [0] * n
        max_area = 0
        for row in matrix:
            for j in range(n):
                heights[j] = heights[j] + 1 if row[j] else 0
            sorted_h = sorted(heights, reverse = True)
            for j in range(n):
                max_area = max(max_area, sorted_h[j] * (j + 1))
        return max_area