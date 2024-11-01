from typing import List


class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        return sum(v if v < 10 else -v for v in nums) != 0
