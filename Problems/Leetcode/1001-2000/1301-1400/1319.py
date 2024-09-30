from typing import List


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        pa = list(range(n))
        size = [1] * n
        cnt = 0

        def find(x: int) -> int:
            if pa[x] != x:
                pa[x] = find(pa[x])
            return pa[x]

        def merge(x: int, y: int) -> None:
            px, py = find(x), find(y)
            if px == py:
                nonlocal cnt
                cnt += 1  # 记录多余的线
                return
            if size[px] > size[py]:
                px, py = py, px
            pa[px] = py
            size[py] += size[px]

        for con in connections:
            merge(con[0], con[1])

        s = set(find(i) for i in range(n))
        return len(s) - 1 if cnt >= len(s) - 1 else -1  # 操作次数等于连通分量个数 -1
