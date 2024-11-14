from typing import List


class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        ans = 0

        def dfs(u: int, pa: int = -1):
            size, pre = 1, 0
            ok = 1
            for v in g[u]:
                if v == pa:
                    continue
                sz = dfs(v, u)
                if pre != 0 and sz != pre:
                    ok = 0
                size += sz
                pre = sz

            nonlocal ans
            ans += ok
            return size

        dfs(0)
        return ans
