if 1:
    from typing import Any, Optional, List
    from collections import Counter
    from functools import cache
    from heapq import heapify, heappop, heappushpop
    from math import inf
    from more_itertools import minmax, sieve
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y

    def I() -> str | Any:
        return input()

    def II() -> int:
        return int(input())

    def LI() -> List[str]:
        return list(input().split())

    def MII():
        return map(int, input().split())

    def LII() -> List[int]:
        return list(map(int, input().split()))

    MOD = 1_000_000_007


def solve():
    n = II()
    s = I()

    a = [(i + 1) * int(s[i]) for i in range(n)]
    for i in range(1, n):
        a[i] += a[i - 1]

    i = c = 0
    ans = []
    while i < n or c > 0:
        if i < n:
            c += a[n - 1 - i]
        ans.append(c % 10)
        c //= 10
        i += 1
    print(*ans[::-1], sep="")


if __name__ == "__main__":
    solve()
