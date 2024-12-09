from typing import List


class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        return [nums[(i + x) % len(nums)] for i, x in enumerate(nums)]
