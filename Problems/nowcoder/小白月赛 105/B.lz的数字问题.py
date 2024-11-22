# Date: 2024-11-22  星期五

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
LGMI = lambda: map(lambda x: int(x) - 1, input().split())


def solve():
    a, b = I().split(" ")

    if "." not in a:
        a += "."
    if "." not in b:
        b += "."

    a += "0" * 6
    b += "0" * 6

    # s = a.split(".")
    # t = b.split(".")
    # print("YES" if s[0] == t[0] and s[1][:6] == t[1][:6] else "NO")
    print("YES" if a[: a.find(".") + 7] == b[: b.find(".") + 7] else "NO")


if __name__ == "__main__":
    solve()
