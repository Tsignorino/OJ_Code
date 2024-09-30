from heapq import heapify, heappop, heappush
from typing import List


class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            nums[nums.index(min(nums))] *= multiplier
        return nums

        """
        堆
        """
        h = [(v, i) for i, v in enumerate(nums)]
        heapify(h)
        for _ in range(k):
            v, idx = heappop(h)
            nums[idx] = v * multiplier
            heappush(h, (nums[idx], idx))
        return nums
