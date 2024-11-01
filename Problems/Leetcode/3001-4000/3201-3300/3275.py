from heapq import heappop, heappush
from sortedcontainers import SortedList
from typing import List

fabs = lambda x: x if x >= 0 else -x


class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        ans = [-1] * len(queries)
        h = []
        for i, (u, v) in enumerate(queries):
            heappush(h, -fabs(u) - fabs(v))  # 最大堆
            if len(h) > k:
                heappop(h)
            if len(h) == k:
                ans[i] = -h[0]
        return ans

        """
        有序列表
        """
        ans = []
        l = SortedList()
        for u, v in queries:
            l.add(fabs(u) + fabs(v))
            ans.append(l[k - 1] if len(l) >= k else -1)
        return ans
