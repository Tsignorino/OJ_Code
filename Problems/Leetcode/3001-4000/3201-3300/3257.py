from functools import cache
from typing import List

# collections  sortedcontainers  more_itertools

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

inf = 1_000_000_007 * 4


class Solution:
    def maximumValueSum(self, board: List[List[int]]) -> int:
        def update(row: List[int]) -> None:
            for j, x in enumerate(row):
                if x > p[0][0]:
                    if p[0][1] != j:
                        if p[1][1] != j:
                            p[2] = p[1]
                        p[1] = p[0]
                    p[0] = (x, j)
                elif j != p[0][1] and x > p[1][0]:
                    if p[1][1] != j:
                        p[2] = p[1]
                    p[1] = (x, j)
                elif j != p[0][1] and j != p[1][1] and x > p[2][0]:
                    p[2] = (x, j)

        m = len(board)
        p = [(-inf, -1)] * 3
        suf = [[] for _ in range(m)]
        for i in range(m - 1, 1, -1):
            update(board[i])
            suf[i] = p[:]

        ans = -inf
        p = [(-inf, -1)] * 3
        for i, row in enumerate(board[:-2]):
            update(row)
            for j, x in enumerate(board[i + 1]):
                for a in p:
                    for b in suf[i + 2]:
                        if a[1] != j and b[1] != j and a[1] != b[1]:
                            ans = fmax(ans, a[0] + x + b[0])
                            break
        return ans
