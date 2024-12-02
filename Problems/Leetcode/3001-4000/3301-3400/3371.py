from math import inf
from typing import Counter, List


class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        total = sum(nums)

        ans = -inf
        for x in nums:
            y, rem = divmod(total - x, 2)
            if rem == 0 and y in cnt and (y != x or cnt[y] > 1):
                ans = max(ans, x)
        return ans
