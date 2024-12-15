from collections import defaultdict
from itertools import pairwise
from math import inf
from typing import List


class Solution:
    def buttonWithLongestTime(self, events: List[List[int]]) -> int:
        d = defaultdict(lambda: inf)
        pre = 0
        for idx, t in events:
            d[t - pre] = min(d[t - pre], idx)
            pre = t
        return d[max(d.keys())]


class Solution:
    def buttonWithLongestTime(self, events: List[List[int]]) -> int:
        idx, max_diff = events[0]
        for (_, t1), (i, t2) in pairwise(events):
            d = t2 - t1
            if d > max_diff or d == max_diff and i < idx:
                idx, max_diff = i, d
        return idx


# print(Solution().buttonWithLongestTime(events=[[1, 2], [2, 5], [3, 9], [1, 15]]))
print(Solution().buttonWithLongestTime(events=[[10, 5], [1, 7]]))
