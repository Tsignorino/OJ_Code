from functools import cache
from typing import List


class Solution:
    def maxScore(self, n: int, k: int, s: List[List[int]], t: List[List[int]]) -> int:
        f = [[0] * n for _ in range(k + 1)]
        for i in range(k - 1, -1, -1):
            for j, v in enumerate(s[i]):
                f[i][j] = max(
                    f[i + 1][j] + v,
                    # max(f[i + 1][d] + v for d, v in enumerate(t[j])),
                    max(v1 + v2 for v1, v2 in zip(f[i + 1], t[j])),
                )
        return max(f[0])

        """
        dfs(i, j) 第 i 天在城市 j 可以获得的最大点数
        """

        @cache
        def dfs(i: int, j: int):
            if i == k:
                return 0
            v1 = dfs(i + 1, j) + s[i][j]
            v2 = max(dfs(i + 1, d) + v for d, v in enumerate(t[j]))
            return max(v1, v2)

        return max(dfs(0, j) for j in range(n))
