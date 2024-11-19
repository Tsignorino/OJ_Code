if 1:
    from functools import cache
    from math import comb, inf
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    lowbit = lambda x: x & -x
    comb = cache(comb)

    def I():
        return input()

    def II():
        return int(input())

    def LI():
        return list(input().split())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))

    MOD = 1_000_000_007


def solve():
    n, x = MII()
    a, b = LII(), LII()

    Aid = sorted(list(range(n)), key=lambda x: a[x])
    Bid = sorted(list(range(n)), key=lambda x: b[x])

    c = [0] * n
    for i in range(n):
        c[Aid[i]] = b[Bid[(i + x) % n]]

    k = sum(a[i] > c[i] for i in range(n))
    if k == x:
        print("YES")
        print(*c)
    else:
        print("NO")

    pass


if __name__ == "__main__":
    for i in range(II()):
        solve()
