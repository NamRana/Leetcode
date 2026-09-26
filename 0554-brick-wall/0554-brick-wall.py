class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        edges = defaultdict(int)

        for row in wall:

            position = 0

            # Don't include the last brick
            for i in range(len(row) - 1):

                position += row[i]

                edges[position] += 1

        # Maximum number of rows where line can pass through an edge
        max_edges = max(edges.values(), default=0)

        return len(wall) - max_edges