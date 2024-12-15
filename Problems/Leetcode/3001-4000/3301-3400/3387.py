from collections import defaultdict
from typing import List


class Solution:
    def maxAmount(
        self, init: str, pairs1: List[List[str]], rates1: List[float], pairs2: List[List[str]], rates2: List[float]
    ) -> float:
        def f(pairs, rates):
            g = defaultdict(lambda: defaultdict(lambda: 0))
            for (u, v), r in zip(pairs, rates):
                g[u][v] = r
                g[v][u] = 1 / r
            for k in g:
                for u in g:
                    for v in g:
                        g[u][v] = max(g[u][v], g[u][k] * g[k][v])
            return g

        g1 = f(pairs1, rates1)
        g2 = f(pairs2, rates2)
        ans = 1.0
        for v in g1[init].keys() & g2[init].keys():
            ans = max(ans, g1[init][v] / g2[init][v])
        return ans


print(
    Solution().maxAmount(
        init="EUR",
        pairs1=[["EUR", "USD"], ["USD", "JPY"]],
        rates1=[2.0, 3.0],
        pairs2=[["JPY", "USD"], ["USD", "CHF"], ["CHF", "EUR"]],
        rates2=[4.0, 5.0, 6.0],
    )
)
