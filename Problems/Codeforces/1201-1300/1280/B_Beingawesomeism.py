if 1:
    import sys
    import typing
    from collections import Counter
    from functools import cache, reduce
    from heapq import heapify, heappop, heappushpop, heapreplace, nlargest, nsmallest
    from math import inf
    from typing import *  # type: ignore

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
    n, m = MII()
    g = [I() for _ in range(n)]
    g2 = ["".join(v) for v in zip(*g)]
    # print(g)
    # print(g2)

    if not any("P" in s for s in g):
        print(0)
    elif not any("A" in s for s in g):
        print("MORTAL")
    elif (  # 第一行或最后一行或第一列或最后一列都是 A
        g[0] == "A" * m or g[-1] == "A" * m or g2[0] == "A" * n or g2[-1] == "A" * n
    ):
        print(1)
    else:
        c = [u == "A" or v == "A" for u, v in zip(g[0], g[-1])]
        r = [u == "A" or v == "A" for u, v in zip(g2[0], g2[-1])]

        if (  # '有一行或者一列均为 A' or '第一行和最后一行的 A 补满一整行 或 第一列和最后一列的 A 补满一整列' or 'A 在四个角之一'
            sum(r) == n
            or sum(c) == m
            or any(s == "A" * m for s in g)
            or any(s == "A" * n for s in g2)
            or "A" in (g[0][0], g[0][-1], g[-1][0], g[-1][-1])
        ):
            print(2)
        elif "A" in g[0] or "A" in g[-1] or "A" in g2[0] or "A" in g2[-1]:  # A 在外围
            print(3)
        else:
            print(4)


if __name__ == "__main__":
    for _ in range(II()):
        solve()
