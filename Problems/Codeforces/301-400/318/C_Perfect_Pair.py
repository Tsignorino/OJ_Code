from math import inf
import sys
import typing

input = lambda: sys.stdin.readline().strip()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 998244353


def solve():
    a, b, m = MII()

    if a <= 0 and b <= 0:
        print(0 if fmax(a, b) >= m else -1)
    else:
        ans = 0
        while fmax(a, b) < m:
            if a > b:
                a, b = b, a
            if a < 0:
                tmp = -a // b
                ans += tmp
                a += tmp * b
            a += b
            ans += 1
        print(ans)


if __name__ == "__main__":
    solve()
