if 1:
    import sys
    from functools import cache
    from math import comb, gcd, inf

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
    n, k = MII()
    l = LII()

    if n == 1:
        print(k - (k <= l[0]))
        return

    g = gcd(*l)
    if g == 0:
        print(k)
        return

    if n + k < n * g:
        t, v = divmod(k - 1, g - 1)
        print(g * t + v + 1)
    else:
        print(k + n - 1)


if __name__ == "__main__":
    for i in range(II()):
        solve()
