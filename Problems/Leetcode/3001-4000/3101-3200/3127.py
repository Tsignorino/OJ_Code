from collections import defaultdict
from typing import List


class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        def check(i: int, j: int) -> bool:
            cnt = defaultdict(int)
            cnt[grid[i][j]] += 1
            cnt[grid[i][j + 1]] += 1
            cnt[grid[i + 1][j]] += 1
            cnt[grid[i + 1][j + 1]] += 1
            return cnt["B"] != 2

        return check(0, 0) or check(0, 1) or check(1, 0) or check(1, 1)
