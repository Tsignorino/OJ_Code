# Date: 2024-12-21  星期六

import sys
import typing

input = lambda: sys.stdin.readline().strip()

I = lambda: input()
II = lambda: int(input())
FI = lambda: float(input())
LI = lambda: list(input().split())
LII = lambda: list(map(int, input().split()))
LFI = lambda: list(map(float, input().split()))
GMI = lambda: list(map(lambda x: int(x) - 1, input().split()))


def solve():
    n = II()
    a = LII()

    ans = []
    tmp = []
    for i, v in enumerate(a):
        if v != 0:
            tmp.append(v)
        if i == n - 1 or v == 0:
            if tmp:
                ans.append(tmp.copy())
                tmp = []
    # print(ans)
    print(2 if (l := len(ans)) > 1 else l)


if __name__ == "__main__":
    for _ in range(II()):
        solve()
