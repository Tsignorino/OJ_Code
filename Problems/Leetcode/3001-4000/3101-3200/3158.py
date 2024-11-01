from typing import List


class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = 0
        vis = 0
        for x in nums:
            if vis >> x & 1:
                ans ^= x
            else:
                vis |= 1 << x
        return ans