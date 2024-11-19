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
    _ = I()
    a = LII()
    print(min(sum(a) // 2, sum(a) - max(a)))
    pass


if __name__ == "__main__":
    solve()
