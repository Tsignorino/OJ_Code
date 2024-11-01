from itertools import pairwise
from typing import List


class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        return min(y - x for x, y in pairwise(sorted(nums)))
