from typing import List


class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        return sum(i * x for i, x in enumerate(sorted(x for row in values for x in row), 1))
