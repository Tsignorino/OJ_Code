if 1:
    import sys
    import typing
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
    n, k = MII()
    a = LII()
    a.sort()

    ans = j = 0
    for i in range(n):
        j = fmax(i, j)
        while j + 1 < n and a[j + 1] <= a[j] + 1 and a[j + 1] < a[i] + k:
            j += 1
        ans = fmax(ans, j - i + 1)
    print(ans)


if __name__ == "__main__":
    for i in range(II()):
        solve()
