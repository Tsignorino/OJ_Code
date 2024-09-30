from typing import List


# 2024/07/28 数据范围较小
class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        n = len(positions)
        h = [0] * n
        for i, (l1, s1) in enumerate(positions):
            r1 = l1 + s1 - 1
            h[i] = s1
            for j in range(i):
                l2 = positions[j][0]
                r2 = l2 + positions[j][1] - 1
                if r1 >= l2 and r2 >= l1:
                    h[i] = max(h[i], h[j] + s1)

        for i in range(1, n):
            h[i] = max(h[i], h[i - 1])
        return h
