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
    n, _ = MII()
    g = [set() for _ in range(n)]

    for _ in range(n - 1):
        a, b = MII()
        a -= 1
        b -= 1
        g[a].add(b)
        g[b].add(a)

    L = set(v - 1 for v in LII())
    q = [i for i, s in enumerate(g) if len(s) == 1]
    ans = n
    for u in q:
        if u in L:
            continue
        v = g[u].pop()
        g[v].discard(u)
        ans -= 1
        if len(g[v]) == 1:
            q.append(v)
    print(ans)


if __name__ == "__main__":
    solve()
