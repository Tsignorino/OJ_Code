from sortedcontainers import SortedSet

if 1:
    import sys
    from functools import cache
    from math import comb, inf

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    lowbit = lambda x: x & -x
    comb = cache(comb)

    def I():
        return input()

    def II():
        return int(input())

    def LI():
        return list(input().split())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))

    MOD = 1_000_000_007


class DSU:
    def __init__(self, n: int) -> None:
        self.pa = list(range(n))
        self._size = [1] * n

        """ 
        modify
        """
        self.pq = [SortedSet([i]) for i in range(n)]

    def find(self, x: int) -> int:
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]

    def merge(self, x: int, y: int) -> None:
        px, py = self.find(x), self.find(y)
        if px == py:
            return
        if self._size[px] > self._size[py]:
            px, py = py, px
        self.pa[px] = py
        self._size[py] += self._size[px]

        """ 
        modify
        """
        self.pq[py].update(self.pq[px])
        # self.pq[px].clear()

    def same(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    def size(self, x: int) -> int:
        return self._size[self.find(x)]


def solve():
    n, q = MII()

    dsu = DSU(n)
    for _ in range(q):
        op, u, v = MII()
        u -= 1
        if op == 1:
            v -= 1
            dsu.merge(u, v)
        else:
            s = dsu.pq[dsu.find(u)]
            if len(s) < v:
                print(-1)
            else:
                print(s[-v] + 1)  # type: ignore
    pass


if __name__ == "__main__":
    solve()
