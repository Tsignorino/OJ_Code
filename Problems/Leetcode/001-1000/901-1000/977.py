from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        i, j = 0, n - 1
        for p in range(n - 1, -1, -1):
            x = nums[i]
            y = nums[j]
            if -x > y:
                ans[p] = x**2
                i += 1
            else:
                ans[p] = y**2
                j -= 1
        return ans
