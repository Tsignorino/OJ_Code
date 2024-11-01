from typing import List


class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        ans = 0
        cnt = [[0] * 10 for _ in str(nums[0])]
        for k, x in enumerate(nums):
            i = 0
            while x:
                x, d = divmod(x, 10)
                ans += k - cnt[i][d]
                cnt[i][d] += 1
                i += 1
        return ans
