if 1:
    from functools import cache
    from math import comb
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    lowbit = lambda x: x & -x
    comb = cache(comb)

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))

    MOD = 1_000_000_007


def query(a: int, b: int):
    print("?", a, b, flush=True)
    return II()


def solve():
    n = II()
    ans = []
    for v in range(2, n + 1):
        u = 1
        while True:
            o = query(v, u)
            if o == v:
                break
            u = o
        ans.append(u)
        ans.append(v)
    print("!", *ans, flush=True)
    pass


if __name__ == "__main__":
    _ = II()
    for i in range(_):
        solve()
