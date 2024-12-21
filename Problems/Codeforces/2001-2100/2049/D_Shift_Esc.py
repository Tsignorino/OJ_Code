# Date: 2024/12/21

import sys
import typing

input = lambda: sys.stdin.readline().strip()

I = lambda: input()
II = lambda: int(input())
FI = lambda: float(input())
LI = lambda: list(input().split())
LII = lambda: list(map(int, input().split()))
LFI = lambda: list(map(float, input().split()))
LMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

inf = 10**18
fmin = lambda x, y: x if x < y else y


def solve():
    n, m, x = LII()
    g = [LII() for _ in range(n)]

    f = [[[inf] * m for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            for k in range(m):
                f[i][j][k] = g[i][(j + k) % m] + (min(f[i - 1][j]) if i > 0 else inf if j > 0 else 0) + k * x
                if j > 0:
                    f[i][j][k] = fmin(f[i][j][k], f[i][j - 1][k] + g[i][(j + k) % m])
    print(min(f[-1][-1]))


if __name__ == "__main__":
    for _ in range(II()):
        solve()
