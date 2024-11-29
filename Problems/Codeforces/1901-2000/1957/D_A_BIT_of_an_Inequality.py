import sys
import typing
from itertools import accumulate
from operator import xor

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
    arr = LII()

    pre = list(accumulate(arr, xor, initial=0))
    cntL = [0] * 30
    cntR = [0] * 30

    for x in pre:
        for i in range(30):
            if x >> i & 1:
                cntR[i] += 1

    ans = 0
    for i in range(n):
        for j in range(30):
            if pre[i] >> j & 1:
                cntL[j] += 1
                cntR[j] -= 1
        b = arr[i].bit_length() - 1
        ans += cntL[b] * cntR[b] + (i + 1 - cntL[b]) * (n - i - cntR[b])
    print(ans)


if __name__ == "__main__":
    for _ in range(II()):
        solve()
