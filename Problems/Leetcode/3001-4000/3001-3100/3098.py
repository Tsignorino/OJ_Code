from collections import defaultdict
from functools import cache
from math import inf
from typing import List


class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        MOD = 1_000_000_007

        n = len(nums)
        nums.sort()

        # dp[i][p][v] 表示以 i 结尾时，长度为 p 且能量为 v 的子序列个数
        d = [[defaultdict(int) for _ in range(k + 1)] for _ in range(n)]
        res = 0
        for i in range(n):
            d[i][1][inf] = 1
            for j in range(i):
                diff = nums[i] - nums[j]
                for p in range(2, k + 1):
                    for v, cnt in d[j][p - 1]:
                        d[i][p][min(diff, v)] = (d[i][p][min(diff, v)] + cnt) % MOD
            for v, cnt in d[i][k]:
                res = (res + v * cnt % MOD) % MOD
        return res
