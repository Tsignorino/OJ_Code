from collections import defaultdict
from typing import List


class Solution:
    def maximizeSumOfWeights(self, edges: List[List[int]], k: int) -> int:
        g = defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))

        def dfs(u: int, pa: int = -1):
            notChoose = 0
            inc = []
            for v, w in g[u]:
                if v == pa:
                    continue
                nc, c = dfs(v, u)
                notChoose += nc
                if (d := c + w - nc) > 0:
                    inc.append(d)
            inc.sort(reverse=True)
            return notChoose + sum(inc[:k]), notChoose + sum(inc[: k - 1])

        return max(dfs(0))
