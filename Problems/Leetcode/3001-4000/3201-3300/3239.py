from typing import List


class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        diff_row = 0
        for row in grid:
            for j in range(len(row) // 2):
                if row[j] != row[-1 - j]:
                    diff_row += 1

        diff_col = 0
        for col in zip(*grid):
            for i in range(len(grid) // 2):
                if col[i] != col[-1 - i]:
                    diff_col += 1

        return min(diff_row, diff_col)
