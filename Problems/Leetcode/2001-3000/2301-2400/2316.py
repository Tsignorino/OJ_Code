from typing import List


class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        pa = list(range(n))
        size = [1] * n

        def find(x: int) -> int:
            if pa[x] != x:
                pa[x] = find(pa[x])
            return pa[x]

        def merge(x: int, y: int) -> None:
            px, py = find(x), find(y)
            if px == py:
                return
            if size[px] > size[py]:
                px, py = py, px
            pa[px] = py
            size[py] += size[px]

        for edge in edges:
            merge(edge[0], edge[1])

        s = set(find(i) for i in range(n))
        lst = [size[v] for v in s]
        tot = sum(lst)
        return sum(v * (tot - v) for v in lst) // 2
