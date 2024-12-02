# Date: 2024-12-02  星期一

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
    n = II()
    a = LII()

    if n == 1:
        print(1)
        return

    suf = [0] * (n // 2 + 1)
    for i in range(n - 2, -1, -2):
        suf[i // 2] = max(suf[i // 2 + 1], a[i + 1] - a[i])

    ans = suf[0]
    if n % 2 == 1:
        pre = 0
        for i in range(1, n, 2):
            pre = max(pre, a[i] - a[i - 1])
            ans = min(ans, max(pre, suf[i // 2 + 1]))
    print(ans)


if __name__ == "__main__":
    for _ in range(II()):
        solve()
