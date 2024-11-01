from typing import List


class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        ans = 0

        def dfs(x: int, pa: int = -1) -> int:
            size, pre = 1, 0
            ok = 1
            for y in g[x]:
                if y == pa:
                    continue
                sz = dfs(y, x)
                if pre > 0 and sz != pre:
                    ok = 0
                pre = sz
                size += sz

            nonlocal ans
            ans += ok
            return size

        dfs(0)
        return ans
