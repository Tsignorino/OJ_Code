from bisect import bisect_left
from collections import defaultdict
from typing import List


class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        """
        一共有 m = n*(n+1)//2 个非空子数组，对应 m 个 distinct 值

        > 二分 + 滑窗
        """

        n = len(nums)
        k = (n * (n + 1) // 2 + 1) // 2

        def check(x: int) -> bool:
            cnt = l = 0
            freq = defaultdict(int)
            for r, v in enumerate(nums):
                freq[v] += 1
                while len(freq) > x:
                    left = nums[l]
                    freq[left] -= 1
                    if freq[left] == 0:
                        del freq[left]
                    l += 1
                cnt += r - l + 1
                if cnt >= k:
                    return True
            return False

        return bisect_left(range(len(set(nums))), True, lo=1, key=check)
