from bisect import bisect_left, bisect_right
from typing import Counter, List


"""
class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        cnt = Counter(nums)
        s = set()
        for v in nums:
            s.add(v)
            s.add(v - k)
            s.add(v + k)

        ans = 1
        for v in s:
            ans = max(ans, min(bisect_right(nums, v + k) - bisect_left(nums, v - k), cnt[v] + numOperations))
        return ans
"""


class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        cnt = Counter(nums)
        diff = Counter()
        for x in nums:
            diff[x] += 0
            diff[x - k] += 1
            diff[x + k + 1] -= 1

        cur = 0
        res = 0
        for v in sorted(diff):
            cur += diff[v]
            res = max(res, cnt[v] + min(cur - cnt[v], numOperations))
        return res
