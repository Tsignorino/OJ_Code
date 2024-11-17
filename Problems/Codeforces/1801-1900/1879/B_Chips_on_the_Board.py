import sys

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
    a = LII()
    b = LII()

    print(fmin(min(a) * n + sum(b), sum(a) + min(b) * n))


if __name__ == "__main__":
    for _ in range(II()):
        solve()
