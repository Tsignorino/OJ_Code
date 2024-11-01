from functools import cache
from math import gcd
from typing import List


class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        @cache
        def dfs(i: int, g1: int = 0, g2: int = 0):
            if i == n:
                return 1 if (g1 == g2) else 0

            return (
                dfs(i + 1, gcd(g1, nums[i]), g2)
                + dfs(i + 1, g1, gcd(g2, nums[i]))
                + dfs(i + 1, g1, g2)
            ) % MOD

        return (dfs(0) - 1) % MOD  # 减去全不选


print(Solution().subsequencePairCount([1, 2, 3, 4]))  # 10
