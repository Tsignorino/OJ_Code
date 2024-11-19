if 1:
    from collections import Counter
    from functools import cache
    from heapq import heapify, heappop, heappushpop
    from math import inf
    from typing import Any, List, Optional
    import sys

    from more_itertools import minmax, sieve

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

    a = [int(x) for x in I()]
    for i in range(n):
        a[i] *= i + 1
    for i in range(1, n):
        a[i] += a[i - 1]

    for i in range(n - 2, -1, -1):
        a[i] += a[i + 1] // 10
        a[i + 1] %= 10

    # print("".join(map(str, a)))
    print(*a, sep="")


if __name__ == "__main__":
    solve()
