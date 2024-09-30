from heapq import heapify, heappop, heappush, heapreplace
from typing import List


"""
整理思路：
    相当于找一个固定的顺序，然后快速幂求解
"""


MOD = 1_000_000_007


class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        if multiplier == 1:
            return nums

        n, mx = len(nums), max(nums)
        h = [(v, i) for i, v in enumerate(nums)]
        heapify(h)

        """
        堆中计算
        """
        while k:
            x, i = h[0]
            if x == mx:
                break
            heapreplace(h, (x * multiplier, i))
            k -= 1

        for i in range(n):
            x, j = heappop(h)
            nums[j] = x * pow(multiplier, k // n + (1 if i < k % n else 0), MOD) % MOD
        return nums

        """
        修改原数组
        """
        while k and h[0][0] * multiplier <= mx:
            _, i = heappop(h)
            nums[i] *= multiplier
            k -= 1
            heappush(h, (nums[i], i))

        order = sorted(range(n), key=lambda i: (nums[i], i))
        p = k // n
        k %= n
        for i in range(n):
            nums[order[i]] *= pow(multiplier, p + (1 if i < k else 0), MOD)
        return [x % MOD for x in nums]
