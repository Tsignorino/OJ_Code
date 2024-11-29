import sys
import typing
from math import inf

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
    a, _ = MII()

    lst = []
    for _ in range(n):
        l, r = MII()
        lst.append((l, r))

    lst.sort(key=lambda x: x[0] * x[1])

    pre = a
    mx = 0
    for _, (l, r) in enumerate(lst):
        mx = max(mx, pre // r)
        pre *= l
    print(mx)


if __name__ == "__main__":
    solve()
