from bisect import bisect_left, bisect_right
from typing import Counter, List


class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        cnt = Counter(nums)
        return max(
            min(bisect_right(nums, v + k) - bisect_left(nums, v - k), numOperations + cnt[v])
            for v in range(nums[-1] + 1)
        )


print(Solution().maxFrequency([88, 53], 27, 2))

"""
[88,53]
27
2

right: 2
"""
