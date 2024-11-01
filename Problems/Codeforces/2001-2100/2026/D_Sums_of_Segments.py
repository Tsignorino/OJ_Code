if 1:
    from typing import Any, Optional, List
    from functools import cache
    from math import comb, inf
    import sys

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


def solve():
    n = II()
    lst = LII()

    pre1 = [0] * (n + 1)
    pre2 = [0] * (n + 1)
    for i, v in enumerate(lst):
        pre1[i + 1] = pre1[i] + v
        pre2[i + 1] = pre2[i] + (n - i) * v

    ppre = [0]
    for i in range(n):
        ppre.append(ppre[-1] + pre2[n] - pre2[i])

    def func(x: int):
        lo, hi = 0, n
        while lo + 1 < hi:
            mid = (lo + hi) // 2
            if (n + n - mid + 1) * mid // 2 < x:
                lo = mid
            else:
                hi = mid

        k = x - (n + n - lo + 1) * lo // 2
        return (
            ppre[lo]
            + (pre2[lo + k] - pre2[lo])
            - (pre1[lo + k] - pre1[lo]) * (n - lo - k)
        )

    for _ in range(II()):
        l, r = MII()
        print(func(r) - func(l - 1))


if __name__ == "__main__":
    solve()
