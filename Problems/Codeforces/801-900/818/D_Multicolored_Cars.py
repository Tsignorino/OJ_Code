if 1:
    import typing
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
    n, a = MII()
    nums = LII()

    M = 10**6
    g = [[] for _ in range(M + 1)]
    for i in range(n):
        g[nums[i]].append(i)

    for i in range(1, M + 1):
        if i == a or len(g[i]) < len(g[a]):
            continue
        if all(g[i][j] <= g[a][j] for j in range(len(g[a]))):
            print(i)
            return
    print(-1)


if __name__ == "__main__":
    solve()
