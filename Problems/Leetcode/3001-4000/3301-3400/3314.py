from typing import List


class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        for i, v in enumerate(nums):
            for k in range(v):
                if (k | (k + 1)) == v:
                    nums[i] = k
                    break
            else:
                nums[i] = -1
        return nums


print(Solution().minBitwiseArray([2, 3, 5, 7]))
