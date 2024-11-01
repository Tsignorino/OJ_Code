from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        pa = list(range(n + 1))

        def find(x: int) -> int:
            if pa[x] != x:
                pa[x] = find(pa[x])
            return pa[x]

        def merge(x: int, y: int):
            pa[find(x)] = find(y)

        for u, v in edges:
            if find(u) != find(v):
                merge(u, v)
            else:
                return [u, v]
        return []
