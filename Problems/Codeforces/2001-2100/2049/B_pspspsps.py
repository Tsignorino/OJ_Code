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


def solve():
    n = II()
    s = I()
    print("YES" if "s" not in s[1:] or "p" not in s[:-1] else "NO")


if __name__ == "__main__":
    for _ in range(II()):
        solve()
