from typing import List


class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        vis = [0] * n

        def dfs(x: int) -> None:
            vis[x] = 1
            nonlocal v, e
            v += 1
            e += len(g[x])
            for y in g[x]:
                if not vis[y]:
                    dfs(y)

        ans = 0
        for i, b in enumerate(vis):
            if not b:
                v = e = 0
                dfs(i)
                if e == v * (v - 1):
                    ans += 1
        return ans
