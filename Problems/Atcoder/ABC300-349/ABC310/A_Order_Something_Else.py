# Date: 2024-12-11  星期三

import sys
import typing

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
    _, p, q = MII()
    a = LII()
    print(min(p, q + min(a)))


if __name__ == "__main__":
    solve()
