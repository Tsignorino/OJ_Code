if 1:
    from collections import Counter
    from functools import cache, reduce
    from heapq import (heapify, heappop, heappushpop, heapreplace, nlargest,
                       nsmallest)
    from math import inf
    from typing import *  # type: ignore
    import sys
    import typing

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
    print(II() - max(Counter(LII()).values()))


if __name__ == "__main__":
    for _ in range(II()):
        solve()
