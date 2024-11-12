from functools import cache
from typing import List


class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        cuts = [0] + cuts + [n]

        @cache
        def dfs(i: int, j: int) -> int:
            if i + 1 == j:
                return 0
            return min(dfs(i, k) + dfs(k, j) for k in range(i + 1, j)) + cuts[j] - cuts[i]

        return dfs(0, len(cuts) - 1)
