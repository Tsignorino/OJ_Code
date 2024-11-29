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

    if n <= 4:
        print(-1)
    else:
        a = list(range(1, n + 1, 2))
        a.remove(5)
        b = list(range(2, n + 1, 2))
        b.remove(4)
        print(*(a + [5, 4] + b))


if __name__ == "__main__":
    for _ in range(II()):
        solve()
