from cmath import inf
from itertools import accumulate
from typing import List


class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = -inf
        s = 0
        f = [-inf] * k
        for i in range(n):
            s += nums[i]
            if i >= k:
                s -= nums[i - k]
            if i >= k - 1:
                f[i % k] = max(f[(i - k) % k] + s, s)
            ans = max(ans, f[i % k])
        return ans


class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        pre = list(accumulate(nums, initial=0))
        min_s = [inf] * k
        ans = -inf
        for j, s in enumerate(pre):
            i = j % k
            ans = max(ans, s - min_s[i])
            min_s[i] = min(min_s[i], s)
        return ans
