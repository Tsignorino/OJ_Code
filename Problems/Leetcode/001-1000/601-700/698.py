from functools import cache
from typing import List


class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k:
            return False

        nums.sort()
        s //= k

        n = len(nums)
        if nums[-1] > s:  # 剪枝
            return False

        # tot 利用二进制表示 `还在数组中的数`
        @cache
        def dfs(tot, p):
            if tot == 0:
                return True
            for i in range(n):
                if nums[i] + p > s:
                    break
                if tot >> i & 1 and dfs(tot ^ (1 << i), (p + nums[i]) % s):
                    return True
            return False

        return dfs((1 << n) - 1, 0)
