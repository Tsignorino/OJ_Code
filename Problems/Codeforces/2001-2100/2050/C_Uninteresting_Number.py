# Date: 2024-12-06  星期五

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
    f = 1
    for i in map(int, I()):
        nf = f << i
        if (x := i * i) < 10:
            nf |= f << x
        nf |= nf >> 9
        nf &= (1 << 9) - 1
        f = nf
        # print("nf: ", bin(nf))
    print("YES" if f & 1 else "NO")


if __name__ == "__main__":
    for _ in range(II()):
        solve()
