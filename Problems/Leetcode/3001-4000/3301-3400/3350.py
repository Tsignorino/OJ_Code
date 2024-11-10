from itertools import accumulate
from typing import Any, Optional, List
from functools import cache
from math import inf
from more_itertools import minmax, sieve

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

MOD = 1_000_000_007


""" 
class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)

        def check(k: int):
            diff = [1 if nums[i] - nums[i - 1] > 0 else 0 for i in range(1, n)]
            acc = list(accumulate(diff, initial=0))
            for i in range(n + 1):
                if i + 2 * k - 1 >= len(acc):
                    break
                if acc[i + k - 1] - acc[i] == k - 1 and acc[i + 2 * k - 1] - acc[i + k] == k - 1:
                    return True
            return False

        l, r = 0, n
        while l + 1 < r:
            m = (l + r) // 2
            if check(m):
                l = m
            else:
                r = m
        return l
"""


class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        ans = pre_cnt = cnt = 0
        for i, x in enumerate(nums):
            cnt += 1
            if i == len(nums) - 1 or x >= nums[i + 1]:  # i 是严格递增段的末尾
                ans = max(ans, cnt // 2, min(pre_cnt, cnt))
                pre_cnt = cnt
                cnt = 0
        return ans


print(Solution().maxIncreasingSubarrays(nums=[2, 5, 7, 8, 9, 2, 3, 4, 3, 1]))
