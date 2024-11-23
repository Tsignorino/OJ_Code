# Date: 2024-11-23  星期六

from itertools import accumulate
import sys
import typing

input = lambda: sys.stdin.readline().strip()

I = lambda: input()
II = lambda: int(input())
FI = lambda: float(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
LFI = lambda: list(map(float, input().split()))
MII = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())


def solve():
    n, m, k = MII()

    g = [LII() for _ in range(n)]

    ans = 0
    cnt = 0
    pre = [0] * (n + 1)
    for i in range(m):
        for j in range(n):
            pre[j + 1] = pre[j] + g[j][i]

        res = 0
        cost = 0
        for j in range(n):
            if g[j][i] == 1:
                if (v := pre[min(j + k, n)] - pre[j]) > res:
                    res = v
                    cost = pre[j]

        ans += res
        cnt += cost
    print(ans, cnt)


if __name__ == "__main__":
    solve()
