from collections import Counter
from math import inf
import sys
import typing

input = lambda: sys.stdin.readline().strip()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 998244353


def solve():
    _ = II()
    print(sum(v // 2 for v in Counter(LII()).values()))


if __name__ == "__main__":
    for _ in range(II()):
        solve()
