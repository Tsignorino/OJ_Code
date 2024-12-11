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
    t = II()
    s = I()
    n = len(s)

    if n % t or all(ch == "9" for ch in s):
        print(("1" + "0" * (t - 1)) * (n // t + 1))
    else:
        ns = s[:t]
        if ns * (v := n // t) > s:
            print(ns * v)
        else:
            ns = list(ns)
            for i in range(t - 1, -1, -1):
                if ns[i] == "9":
                    ns[i] = "0"
                else:
                    ns[i] = chr(ord(ns[i]) + 1)
                    break
            print("".join(ns) * (n // t))


if __name__ == "__main__":
    solve()
