from collections import defaultdict
from typing import List


class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        ls = [defaultdict(int) for _ in range(n)]
        for u, v in pick:
            ls[u][v] += 1

        return sum(any(ls[i][v] > i for v in ls[i]) for i in range(n))
