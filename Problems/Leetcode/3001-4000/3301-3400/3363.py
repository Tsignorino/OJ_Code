from math import inf
from typing import List


class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)

        def solve(fruits) -> int:
            f = [[-inf] * (n + 1) for _ in range(n - 1)]
            f[0][n - 1] = fruits[0][-1]
            for i in range(1, n - 1):
                for j in range(max(n - 1 - i, i + 1), n):
                    f[i][j] = max(f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]) + fruits[i][j]
            return f[-1][n - 1]

        return sum(row[i] for i, row in enumerate(fruits)) + solve(fruits) + solve(list(zip(*fruits)))
