from heapq import heapify, heapreplace
from typing import List


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        h = [(arr[0], i, 0) for i, arr in enumerate(nums)]
        heapify(h)

        L = h[0][0]
        R = r = max(arr[0] for arr in nums)
        while h[0][2] + 1 < len(nums[h[0][1]]):
            _, i, j = h[0]
            x = nums[i][j + 1]
            heapreplace(h, (x, i, j + 1))

            l, r = h[0][0], max(r, x)
            if r - l < R - L:
                L, R = l, r
        return [L, R]
