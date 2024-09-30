if 1:
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    lowbit = lambda x: x & -x

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))

    MOD = 998244353


class Combinatorics:
    def __init__(self, MX) -> None:
        self.f = [1] * (MX + 1)
        self.g = [1] * (MX + 1)
        for i in range(2, MX + 1):
            self.f[i] = self.f[i - 1] * i % MOD
        self.g[-1] = pow(self.f[-1], -1, MOD)
        for i in range(MX, 1, -1):
            self.g[i - 1] = self.g[i] * i % MOD

    def fact(self, n) -> int:
        return self.f[n]

    def fact_inv(self, n) -> int:
        return self.g[n]

    def inv(self, n) -> int:
        return self.f[n - 1] * self.g[n] % MOD

    def perm(self, n, m) -> int:
        if m < 0 or n < 0 or n < m:
            return 0
        return self.f[n] * self.g[n - m] % MOD

    def comb(self, n, m) -> int:
        if m < 0 or n < 0 or n < m:
            return 0
        return self.f[n] * self.g[m] * self.g[n - m] % MOD


C = Combinatorics(2 * 10**5)


def solve():
    n, k = MII()
    a = [-1] + LII()

    f = [1] + [0] * n
    for i in range(1, n + 1):
        f[i] = f[i - 1] * (k + i - 1) * C.inv(i) % MOD

    for i in range(1, n + 1):
        cnt = 1
        j = i + lowbit(i)
        while j <= n:
            a[j] = (a[j] - f[cnt] * a[i]) % MOD
            j += lowbit(j)
            cnt += 1

    print(*a[1:])
    pass


if __name__ == "__main__":
    _ = II()
    for i in range(_):
        solve()
