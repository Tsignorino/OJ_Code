from collections import Counter
from typing import List


class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        d = Counter(x // k for x in nums1 if x % k == 0)
        if not d:
            return 0

        ans = 0
        mx = max(d)
        for x, c in Counter(nums2).items():
            s = sum(d[y] for y in range(x, mx + 1, x))
            ans += s * c
        return ans
