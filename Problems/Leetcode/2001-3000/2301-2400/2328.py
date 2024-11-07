from functools import cache
from typing import List


dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

MOD = 10**9 + 7


class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])

        @cache
        def dfs(x: int, y: int):
            res = 1
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] > grid[x][y]:
                    res += dfs(nx, ny)
                    res %= MOD
            return res

        ans = 0
        for i in range(n):
            for j in range(m):
                ans += dfs(i, j)
                ans %= MOD
        return ans
