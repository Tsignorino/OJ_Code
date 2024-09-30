from collections import deque
from typing import List


class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        ans = int(1e5)
        mn = ans
        g = [[] for _ in range(n)]
        for x, y, d in roads:
            g[x - 1].append((y - 1, d))
            g[y - 1].append((x - 1, d))

        vis = [0] * n
        q = deque()
        q.append(0)
        vis[0] = 1
        while q:
            x = q.popleft()
            for y, d in g[x]:
                ans = min(ans, d)
                if ans == min:
                    return ans
                if not vis[y]:
                    q.append(y)
                    vis[y] = 1
        return ans

        """
        DFS
        """
        # ans = int(1e9)
        # vis = [0] * n

        # def dfs(x: int) -> None:
        #     nonlocal ans
        #     vis[x] = 1
        #     for y, d in g[x]:
        #         ans = min(ans, d)
        #         if not vis[y]:
        #             dfs(y)

        # dfs(0)
        # return ans

        """
        并查集
        """
        # pa = list(range(n))
        # mn = [int(1e5)] * n

        # def find(x: int) -> int:
        #     if pa[x] != x:
        #         pa[x] = find(pa[x])
        #     return pa[x]

        # def merge(x: int, y: int, w: int) -> None:
        #     px, py = find(x), find(y)
        #     mn[px] = min(mn[px], w)
        #     mn[py] = min(mn[py], w)

        #     pa[px] = py
        #     mn[py] = min(mn[px], mn[py])

        # for road in roads:
        #     merge(road[0] - 1, road[1] - 1, road[2])

        # return mn[find(0)]
