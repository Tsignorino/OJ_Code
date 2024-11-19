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

    if n % 2 == 1:
        print(n)

        ans = [2, 1] + list(range(3, n + 1))
    else:
        k = n.bit_length()
        print((1 << k) - 1)

        x = (1 << (k - 1)) - 1
        ans = list(range(2, n, 2)) + list(range(1, n, 2))
        ans.remove(x)
        ans.remove(x - 1)
        ans.extend([x - 1, x, n])

    print(*ans)


if __name__ == "__main__":
    for i in range(II()):
        solve()
