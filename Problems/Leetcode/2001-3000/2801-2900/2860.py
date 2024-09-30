from itertools import pairwise
from typing import List


class Solution:
    def countWays(self, nums: List[int]) -> int:
        nums.sort()
        ans = nums[0] > 0
        for i, (x, y) in enumerate(pairwise(nums), 1):
            if x < i < y:
                ans += 1
        return ans + 1  # 一定能全选
