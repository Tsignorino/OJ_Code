from itertools import accumulate
from typing import List


class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        a = [0] * (len(nums) + 1)
        for l, r in queries:
            a[l] += 1
            a[r + 1] -= 1
        return all(u >= v for u, v in zip(accumulate(a), nums))


print(Solution().isZeroArray([1, 0, 1], [[0, 2]]))
