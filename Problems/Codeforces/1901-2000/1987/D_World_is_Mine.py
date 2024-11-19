from collections import Counter
from math import inf
import sys

input = lambda: sys.stdin.readline().strip()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGII = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 1_000_000_007


def solve():
    n = II()
    a = LGII()
    d = Counter(a)

    dp = [0] + [inf] * n
    for k in range(n):
        ndp = [inf] * (n + 1)
        for i in range(k + 1):
            ndp[i + 1] = fmin(ndp[i + 1], dp[i] + 1)
            if i >= d[k]:
                ndp[i - d[k]] = fmin(ndp[i - d[k]], dp[i])
        dp = ndp
    print(min(dp))


if __name__ == "__main__":
    for _ in range(II()):
        solve()
