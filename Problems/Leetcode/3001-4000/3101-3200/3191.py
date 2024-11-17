from typing import List

"""
https://codeforces.com/problemset/problem/1955/E
"""


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = 0
        for i in range(n - 2):
            if nums[i] == 0:
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                cnt += 1
        return cnt if nums[n - 1] == 1 and nums[n - 2] == 1 else -1
