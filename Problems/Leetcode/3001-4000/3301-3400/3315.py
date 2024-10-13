from typing import List


class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        for i, v in enumerate(nums):
            if v == 2:
                nums[i] = -1
            else:
                t = ~v
                nums[i] ^= (t & -t) >> 1
        return nums
