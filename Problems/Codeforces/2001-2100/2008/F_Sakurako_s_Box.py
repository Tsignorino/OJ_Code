if 1:
    import sys
    from functools import cache
    from math import comb, inf

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
    n = II()
    l = LII()

    print((sum(l) ** 2 - sum(x**2 for x in l)) * pow(n * (n - 1), -1, MOD) % MOD)


if __name__ == "__main__":
    for i in range(II()):
        solve()
