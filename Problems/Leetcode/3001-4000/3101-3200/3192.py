from itertools import pairwise
from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        k = 0
        for x in nums:
            if x == k % 2:
                k += 1
        return k

        # return (nums[0] ^ 1) + sum(x ^ y for x, y in pairwise(nums))
