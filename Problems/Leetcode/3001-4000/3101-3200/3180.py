from typing import List


class Solution:
    def maxTotalReward(self, l: List[int]) -> int:
        # l.sort()
        l = list(set(l))
        n, m = len(l), l[-1] * 2

        f = [0] * m
        f[0] = 1
        for i in range(n):
            v = l[i]
            for j in range(2 * v - 1, v - 1, -1):
                f[j] |= f[j - l[i]]

        for i in range(m - 1, -1, -1):
            if f[i]:
                return i
        return -1
