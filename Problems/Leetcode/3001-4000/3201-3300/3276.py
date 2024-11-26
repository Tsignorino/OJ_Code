from collections import defaultdict
from functools import cache
from typing import List


class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        pos = defaultdict(list)
        for i, r in enumerate(grid):
            for x in set(r):
                pos[x].append(i)

        nums = list(pos)

        @cache
        def dfs(i: int, j: int) -> int:
            if i < 0:
                return 0
            res = dfs(i - 1, j)
            for k in pos[nums[i]]:
                if j >> k & 1 == 0:
                    res = max(res, dfs(i - 1, j | 1 << k) + nums[i])
            return res

        return dfs(len(nums) - 1, 0)
