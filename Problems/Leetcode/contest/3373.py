from typing import List


class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        def func(edges: List[List[int]]) -> tuple[list[list], list[int]]:
            g = [[] for _ in range(len(edges) + 1)]
            for x, y in edges:
                g[x].append(y)
                g[y].append(x)

            cnt = [0, 0]

            def dfs(x: int, pa: int, d: int) -> None:
                cnt[d] += 1
                for y in g[x]:
                    if y != pa:
                        dfs(y, x, d ^ 1)

            dfs(0, -1, 0)
            return g, cnt

        g, cnt1 = func(edges1)
        _, cnt2 = func(edges2)
        mx = max(cnt2)  # * guarantee: n >= 2 and m >= 2
        ans = [mx] * len(g)

        def dfs(x: int, pa: int, d: int) -> None:
            ans[x] += cnt1[d]
            for y in g[x]:
                if y != pa:
                    dfs(y, x, d ^ 1)

        dfs(0, -1, 0)
        return ans
