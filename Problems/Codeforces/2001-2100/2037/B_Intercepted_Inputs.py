from collections import Counter, defaultdict
from math import inf
from random import shuffle
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
    n = II()
    a = LII()

    d = [0] * (n + 1)
    for v in a:
        d[v] += 1

    n -= 2
    for u in range(1, n + 1):
        if u * u > n:
            break
        if n % u:
            continue
        v = n // u
        if u != v and d[u] and d[v] or u == v and d[u] >= 2:
            print(u, v)
            return


if __name__ == "__main__":
    for _ in range(II()):
        solve()
