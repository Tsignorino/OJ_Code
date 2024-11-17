import sys
import typing
from collections import defaultdict

input = lambda: sys.stdin.readline().strip()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 1_000_000_007


def solve():
    n = II()

    a = [0] * (n + 1)
    if n % 2 == 0:
        for i in range(1, n + 1):
            a[i] = (i + 1) // 2
    elif n < 27:
        print(-1)
        return
    else:
        x = 3
        d = defaultdict(int)
        for i in range(1, n + 1):
            if i in (1, 10, 26):
                a[i] = 1
            elif i in (23, 27):
                a[i] = 2
            else:
                a[i] = x
                d[x] += 1
                if d[x] == 2:
                    x += 1
    print(*a[1:])


if __name__ == "__main__":
    for _ in range(II()):
        solve()
