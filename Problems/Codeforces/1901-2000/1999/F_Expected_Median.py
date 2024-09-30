if 1:
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    MOD = 1_000_000_007

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))


class Combinatorics:
    def __init__(self, MX):
        self.f = [1] * (MX + 1)
        self.g = [1] * (MX + 1)
        for i in range(2, MX + 1):
            self.f[i] = self.f[i - 1] * i % MOD
        self.g[-1] = pow(self.f[-1], -1, MOD)
        for i in range(MX, 1, -1):
            self.g[i - 1] = self.g[i] * i % MOD

    def fact(self, n):
        return self.f[n]

    def fact_inv(self, n):
        return self.g[n]

    def inv(self, n):
        return self.f[n - 1] * self.g[n] % MOD

    def perm(self, n, m):
        if m < 0 or n < 0 or n < m:
            return 0
        return self.f[n] * self.g[n - m] % MOD

    def comb(self, n, m):
        if m < 0 or n < 0 or n < m:
            return 0
        return self.f[n] * self.g[m] * self.g[n - m] % MOD


C = Combinatorics(2 * 10**5)


def solve():
    n, k = MII()
    c1 = sum(LII())
    c0 = n - c1

    res = 0
    for i in range((k + 1) // 2, k + 1):
        res = (res + C.comb(c1, i) * C.comb(c0, k - i)) % MOD
    print(res)
    pass


if __name__ == "__main__":
    _ = 1
    _ = II()
    for i in range(_):
        solve()
