# Date: 2024-11-27  星期三

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
    _ = II()

    print("1 1", flush=True)
    a = II()

    print("1 11", flush=True)
    b = II()

    print("1 01", flush=True)
    c = II()

    r = 0 if a == b + c else 1
    print(0, 1, r, flush=True)

    II()


if __name__ == "__main__":
    for _ in range(II()):
        solve()
