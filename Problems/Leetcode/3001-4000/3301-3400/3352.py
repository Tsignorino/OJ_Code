from functools import cache


class Solution:
    def countKReducibleNumbers(self, s: str, k: int) -> int:
        """
        线性 DP + 数位 DP
        """
        MOD = 10**9 + 7

        n = len(s)

        @cache
        def dfs(i: int, left: int, isLimit: int) -> int:
            if i == n:
                return 0 if isLimit or left else 1
            up = int(s[i]) if isLimit else 1
            res = 0
            for d in range(min(up, left) + 1):
                res += dfs(i + 1, left - d, isLimit and d == up)
            return res % MOD

        ans = 0
        f = [0] * n
        for i in range(1, n):
            f[i] = f[i.bit_count()] + 1
            if f[i] <= k:
                ans += dfs(0, i, True)

        dfs.cache_clear()
        return ans % MOD
