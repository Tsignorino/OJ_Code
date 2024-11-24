from heapq import heappop, heappush
from typing import List


class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        """
        贪心 + 最大堆 + 差分数组
        · 贪心：区间右端点越大越好
        · 最大堆维护左端点不大于当前下标的未选区间的右端点
            · 将区间按照左端点排序
        · 差分数组维护区间减一操作
        """
        queries.sort(key=lambda q: q[0])
        h = []
        d = [0] * (len(nums) + 1)
        s = j = 0
        for i, x in enumerate(nums):
            s += d[i]
            while j < len(queries) and queries[j][0] <= i:
                heappush(h, -queries[j][1])
                j += 1
            while s < x and h and -h[0] >= i:
                d[-heappop(h) + 1] -= 1
                s += 1
            if s < x:
                return -1
        return len(h)
