from typing import List


class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        g = [[] for _ in range(n)]
        for x, y in invocations:
            g[x].append(y)

        vis = [0] * n

        def dfs(x: int):
            vis[x] = 1
            for y in g[x]:
                if vis[y] == 0:
                    dfs(y)

        dfs(k)

        for x, y in invocations:
            if vis[x] == 0 and vis[y] == 1:
                return list(range(n))
        return [i for i in range(n) if vis[i] == 0]
