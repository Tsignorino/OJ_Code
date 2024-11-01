from typing import List


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        """
        反向建图
        """
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[v].append(u)

        def dfs(x: int):
            vis[x] = 1
            for y in g[x]:
                if not vis[y]:
                    dfs(y)

        ans = [[] for _ in range(n)]
        for i in range(n):
            vis = [0] * n
            dfs(i)
            vis[i] = 0
            ans[i] = [j for j, v in enumerate(vis) if v]
        return ans

        """
        正向建图
        """
        # g = [[] for _ in range(n)]
        # for u, v in edges:
        #     g[u].append(v)

        # ans = [[] for _ in range(n)]
        # vis = [-1] * n

        # def dfs(x: int):
        #     vis[x] = i
        #     for y in g[x]:
        #         if vis[y] != i:
        #             ans[y].append(i)
        #             dfs(y)

        # for i in range(n):
        #     dfs(i)
        # return ans
