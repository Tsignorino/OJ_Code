from functools import cache
from typing import List


class Solution:
    def numberOfPermutations(self, n: int, requirements: List[List[int]]) -> int:
        """
        dfs(i, j) 表示前 i 个数逆序对为 j 的排列的个数

        前面有 k 个数比 perm[i] 大，有 dfs(i, j) = sum(dfs(i-1, j-k)) (0<=k<=min(i, j))
        """
        MOD = 10**9 + 7
        req = [-1] * n
        req[0] = 0
        for end, cnt in requirements:
            req[end] = cnt
        if req[0]:
            return 0

        # @cache
        # def dfs(i: int, j: int) -> int:
        #     if i == 0:
        #         return 1

        #     r = req[i - 1]
        #     if r >= 0:
        #         return dfs(i - 1, r) if r <= j <= i + r else 0
        #     return sum(dfs(i - 1, j - k) for k in range(min(i, j) + 1)) % MOD

        # return dfs(n - 1, req[-1])

        """
        空间优化 + 前缀和
        """
        m = max(req)
        f = [0] * (m + 1)
        f[0] = 1
        for i in range(1, n):
            mx = m if req[i] < 0 else req[i]
            r = req[i - 1]
            if r >= 0:
                for j in range(m + 1):
                    f[j] = f[r] if r <= j <= min(i + r, mx) else 0
            else:
                for j in range(1, mx + 1):
                    f[j] = (f[j] + f[j - 1]) % MOD
                for j in range(mx, i, -1):
                    f[j] = (f[j] - f[j - i - 1]) % MOD
        return f[req[-1]]
