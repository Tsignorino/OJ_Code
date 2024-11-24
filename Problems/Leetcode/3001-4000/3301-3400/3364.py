from itertools import accumulate
from typing import List


class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        pre = list(accumulate(nums, initial=0))
        ans = -1
        for s in range(l, r + 1):
            for i in range(len(nums) - s + 1):
                if (v := pre[i + s] - pre[i]) > 0 and (ans == -1 or ans > v):
                    ans = v
        return ans


class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        ans = -1
        for i in range(n):
            s = 0
            for j in range(i, n):
                s += nums[j]
                if l <= j - i + 1 <= r and s > 0 and (ans == -1 or ans > s):
                    ans = s
        return ans
