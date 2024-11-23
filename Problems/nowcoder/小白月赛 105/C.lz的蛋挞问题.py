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
GMI = lambda: map(lambda x: int(x) - 1, input().split())


def solve():
    n = II()

    s = "x" + I() + "x"
    t = "x" + I() + "x"

    def func(s: str, t: str):
        ans = 0
        for i in range(1, n + 1):
            if s[i] == "x":
                continue
            if s[i - 1] == "x" and s[i + 1] == "x" and t[i] == "x":
                ans += 1
            elif s[i - 1] == "." and s[i + 1] == "." and t[i] == "x":
                ans += 1
            elif s[i + 1] == "." and t[i] == "." and t[i + 1] == "x":
                ans += 1
            elif s[i - 1] == "." and t[i] == "." and t[i - 1] == "x":
                ans += 1
        return ans

    print(func(s, t) + func(t, s))


if __name__ == "__main__":
    solve()
