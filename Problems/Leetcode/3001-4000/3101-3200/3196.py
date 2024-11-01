from functools import cache
from typing import List


class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:
        """
        划分型 DP
        """
        f0, f1 = 0, nums[0]
        for i in range(1, len(nums)):
            f0, f1 = f1, max(f1 + nums[i], f0 + nums[i - 1] - nums[i])
        return f1

        # @cache
        # def dfs(i: int) -> int:
        #     if i < 0:
        #         return 0
        #     if i == 0:
        #         return nums[0]
        #     return max(dfs(i - 1) + nums[i], dfs(i - 2) + nums[i - 1] - nums[i])
        #
        # return dfs(len(nums) - 1)
