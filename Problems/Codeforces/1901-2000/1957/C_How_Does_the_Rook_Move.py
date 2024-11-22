import sys
import typing

input = lambda: sys.stdin.readline().strip()

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 10**9 + 7


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


C = Combinatorics(3 * 10**5 + 10)


def solve():
    n, k = MII()

    for _ in range(k):
        r, c = MII()
        if r == c:
            n -= 1
        else:
            n -= 2

    ans = 0
    for i in range(n + 1):
        if (n - i) % 2:
            continue
        ans += C.comb(n, i) * C.fact(n - i) * C.fact_inv((n - i) // 2)
        ans %= MOD
    print(ans)


if __name__ == "__main__":
    for _ in range(II()):
        solve()
