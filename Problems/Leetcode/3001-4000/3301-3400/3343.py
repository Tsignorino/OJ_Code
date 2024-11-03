from collections import Counter
from functools import cache

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


C = Combinatorics(200)


class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        n = len(num)
        a = list(map(int, num))
        cnt = Counter(a)
        tot = sum(a)
        if tot % 2:
            return 0

        @cache
        def dfs(i, s, c):
            if s > tot // 2:
                return 0
            if i == 10:
                if s != tot // 2:
                    return 0
                if c == len(num) // 2:
                    return C.f[c] * C.f[n - c] % MOD
                return 0
            ans = 0
            for j in range(cnt[i] + 1):
                ans += dfs(i + 1, s + j * i, c + j) * C.g[j] * C.g[cnt[i] - j] % MOD
                ans %= MOD
            return ans

        return dfs(0, 0, 0)


# print(Solution().countBalancedPermutations("123"))
