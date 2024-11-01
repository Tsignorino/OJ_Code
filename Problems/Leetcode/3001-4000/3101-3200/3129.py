from functools import lru_cache


class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        # limit 表示至多有连续多少个 0 或 1
        # 定义 dfs(i, j, k) 表示用 i 个 0 和 j 个 1 构造稳定数组的方案数，其中第 i+j 个位置填 k

        MOD = 1_000_000_007

        @lru_cache()
        def dfs(i: int, j: int, k: int) -> int:
            if i == 0:
                return 1 if k == 1 and j <= limit else 0
            if j == 0:
                return 1 if k == 0 and i <= limit else 0

            if k == 0:
                return (
                    dfs(i - 1, j, 0)
                    + dfs(i - 1, j, 1)
                    - (dfs(i - limit - 1, j, 1) if i > limit else 0)
                ) % MOD
            else:
                return (
                    dfs(i, j - 1, 0)
                    + dfs(i, j - 1, 1)
                    - (dfs(i, j - limit - 1, 0) if j > limit else 0)
                ) % MOD

        ans = (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD
        dfs.cache_clear()
        return ans
