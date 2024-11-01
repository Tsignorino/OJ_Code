from math import gcd, lcm
from typing import List


class Solution:
    def maxScore(self, nums: List[int]) -> int:
        """
        前后缀
        """
        n = len(nums)
        suf_gcd = [0] * (n + 1)
        suf_lcm = [0] * n + [1]
        for i in range(n - 1, -1, -1):
            suf_gcd[i] = gcd(suf_gcd[i + 1], nums[i])
            suf_lcm[i] = lcm(suf_lcm[i + 1], nums[i])

        ans = suf_gcd[0] * suf_lcm[0]
        pre_gcd, pre_lcm = 0, 1
        for i, x in enumerate(nums):
            ans = max(ans, gcd(pre_gcd, suf_gcd[i + 1]) * lcm(pre_lcm, suf_lcm[i + 1]))
            pre_gcd = gcd(pre_gcd, x)
            pre_lcm = lcm(pre_lcm, x)
        return ans

        """
        暴力
        """
        ans = lcm(*nums) * gcd(*nums)
        for i in range(len(nums)):
            lst = nums[:i] + nums[i + 1 :]
            # print(lst)
            ans = max(ans, lcm(*lst) * gcd(*lst))
        return ans
