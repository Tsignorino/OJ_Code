from typing import List


class Solution:
    def shiftDistance(self, s: str, t: str, nextCost: List[int], previousCost: List[int]) -> int:
        ans = 0
        for c1, c2 in zip(s, t):
            c1 = ord(c1) - ord("a")
            c2 = ord(c2) - ord("a")

            v = c1
            x = 0
            while v != c2:
                x += nextCost[v]
                v += 1
                if v == 26:
                    v = 0

            v = c1
            x1 = 0
            while v != c2:
                x1 += previousCost[v]
                v -= 1
                if v == -1:
                    v = 25

            ans += min(x, x1)
        return ans
