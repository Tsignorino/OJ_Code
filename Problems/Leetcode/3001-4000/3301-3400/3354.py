from typing import List


class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        pre, suf = 0, sum(nums)
        ans = 0
        for x in nums:
            if x:
                pre += x
                suf -= x
            elif pre == suf:
                ans += 2
            elif abs(pre - suf) == 1:
                ans += 1
        return ans
