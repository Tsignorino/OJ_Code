from itertools import accumulate
from typing import List


class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        n = len(nums)
        d = [0] * (k + 2)
        for i in range(n // 2):
            p, q = nums[i], nums[n - 1 - i]
            if p > q:
                p, q = q, p
            x = q - p
            mx = max(q, k - p)

            # [0, x-1] +1
            d[0] += 1
            d[x] -= 1
            # [x+1, mx] +1
            d[x + 1] += 1
            d[mx + 1] -= 1
            # [mx+1, k] +2
            d[mx + 1] += 2
        return min(accumulate(d))
