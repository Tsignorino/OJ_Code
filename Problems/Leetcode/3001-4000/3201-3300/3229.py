from itertools import pairwise
from typing import List


class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        s = target[0] - nums[0]
        ans = abs(s)
        for (a, b), (c, d) in pairwise(zip(nums, target)):
            k = (d - c) - (b - a)
            if k > 0:
                ans += k if s >= 0 else max(k + s, 0)
            else:
                ans -= k if s <= 0 else min(k + s, 0)
            s += k
        return ans
