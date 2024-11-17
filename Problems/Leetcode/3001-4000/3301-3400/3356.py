from itertools import accumulate
from typing import List


class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        def check(k: int) -> bool:
            a = [0] * (len(nums) + 1)
            for l, r, val in queries[:k]:
                a[l] += val
                a[r + 1] -= val
            return all(u >= v for u, v in zip(accumulate(a), nums))

        n = len(queries)
        lo, hi = -1, n + 1
        while lo + 1 < hi:
            mid = (lo + hi) // 2
            if check(mid):
                hi = mid
            else:
                lo = mid
        return hi if hi <= n else -1
