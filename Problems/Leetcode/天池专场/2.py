from typing import List

# 上下左右
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


class Solution:
    def getLength(self, grid: List[str]) -> int:
        n, m = len(grid), len(grid[0])
        ans = x = y = 0
        d = 1
        while 0 <= x < n and 0 <= y < m:
            ans += 1
            if grid[x][y] == "L":  # 左 -> 上，下 -> 右
                d ^= 2
            elif grid[x][y] == "R":  # 右 -> 上，下 -> 左
                d ^= 3
            x += dx[d]
            y += dy[d]
        return ans
