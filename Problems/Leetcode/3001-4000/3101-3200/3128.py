from typing import List

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
MOD = 1_000_000_007


class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        colSum = [sum(col) - 1 for col in zip(*grid)]
        ans = 0
        for row in grid:
            rowSum = sum(row) - 1
            ans += rowSum * sum(c for x, c in zip(row, colSum) if x)
        return ans

        # n, m = len(grid), len(grid[0])
        # rows = [0] * n
        # cols = [0] * m
        # for i in range(0, n):
        #     for j in range(0, m):
        #         if grid[i][j] == 0:
        #             continue
        #         rows[i] += 1
        #         cols[j] += 1

        # ans = 0
        # for i in range(0, n):
        #     for j in range(0, m):
        #         if grid[i][j] == 0:
        #             continue
        #         ans += (rows[i] - 1) * (cols[j] - 1)
        # return ans
