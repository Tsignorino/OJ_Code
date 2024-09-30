if 1:
    from bisect import bisect_left
    from itertools import accumulate, permutations
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


def solve():
    n = II()

    a, pre = [], []
    for _ in range(3):
        lst = LII()
        a.append(lst)
        pre.append(list(accumulate(lst, initial=0)))

    s = pre[0][n]

    g = list(permutations([0, 1, 2]))

    for k in range(6):
        ans = [0] * 6
        id, ok = 0, 1

        for _, i in enumerate(g[k]):
            j = bisect_left(pre[i], pre[i][id] + (s + 2) // 3, lo=id + 1)
            if j == n + 1:
                ok = 0
                break
            ans[i * 2] = id + 1
            ans[i * 2 + 1] = j
            id = j

        if ok == 1:
            print(*ans)
            return

    print(-1)


if __name__ == "__main__":
    for i in range(II()):
        solve()
