from typing import List

"""
可达性
"""


class Solution:
    def maximumDetonation(self, nums: List[List[int]]) -> int:
        n = len(nums)
        g = [[] for _ in range(n)]
        for i, (x1, y1, r) in enumerate(nums):
            for j, (x2, y2, _) in enumerate(nums):
                dx, dy = x1 - x2, y1 - y2
                if dx * dx + dy * dy <= r * r:
                    g[i].append(j)

        def dfs(x: int) -> int:
            vis[x] = 1
            cnt = 1
            for y in g[x]:
                if vis[y] == 0:
                    cnt += dfs(y)
            return cnt

        ans = 0
        for i in range(n):
            vis = [0] * n
            ans = max(ans, dfs(i))
        return ans

    def _maximumDetonation(self, nums: List[List[int]]) -> int:
        n = len(nums)
        f = [0] * n
        for i, (x1, y1, r) in enumerate(nums):
            for j, (x2, y2, _) in enumerate(nums):
                dx, dy = x1 - x2, y1 - y2
                if dx * dx + dy * dy <= r * r:
                    f[i] |= 1 << j

        for k in range(n):
            for i in range(n):
                if f[i] >> k & 1:
                    f[i] |= f[k]

        return max(v.bit_count() for v in f)
