# Date: 2024-12-11  星期三

import sys
import typing
from functools import reduce
from operator import or_

input = lambda: sys.stdin.readline().strip()

I = lambda: input()
II = lambda: int(input())
FI = lambda: float(input())
LFI = lambda: list(map(float, input().split()))
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MI = lambda: map(int, input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))


def solve():
    n, m = MII()
    a = []
    for _ in range(n):
        p, _, *args = MII()
        a.append((p, reduce(or_, (map(lambda x: 1 << (x - 1), args)))))

    for i, x in enumerate(a):
        for j, y in enumerate(a):
            if i == j:
                continue
            if (x[1] | y[1]) == y[1]:
                if x[0] > y[0] or x[0] == y[0] and x[1] < y[1]:
                    print("Yes")
                    return
    print("No")


if __name__ == "__main__":
    solve()
