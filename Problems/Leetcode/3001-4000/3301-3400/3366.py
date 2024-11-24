from functools import cache
from typing import List

fmin = lambda x, y: x if x < y else y


class Solution:
    def minArraySum(self, nums: List[int], k: int, op1: int, op2: int) -> int:
        s = sum(nums)
        n = len(nums)

        @cache
        def dfs(i: int, op1: int, op2: int):
            if i == n:
                return 0
            if op1 < 0 or op2 < 0:
                return s

            res = dfs(i + 1, op1, op2) + nums[i]
            if op1 > 0:
                res = fmin(res, dfs(i + 1, op1 - 1, op2) + (nums[i] + 1) // 2)
            if op2 > 0 and nums[i] >= k:
                res = fmin(res, dfs(i + 1, op1, op2 - 1) + nums[i] - k)
            if op1 > 0 and op2 > 0 and (nums[i] + 1) // 2 >= k:
                res = fmin(res, dfs(i + 1, op1 - 1, op2 - 1) + (nums[i] + 1) // 2 - k)
            if op2 > 0 and nums[i] >= k and op1 > 0:
                res = fmin(res, dfs(i + 1, op1 - 1, op2 - 1) + (nums[i] - k + 1) // 2)
            return res

        ans = dfs(0, op1, op2)
        dfs.cache_clear()
        return ans
