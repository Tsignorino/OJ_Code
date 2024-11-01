from typing import List

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
fabs = lambda x: x if x >= 0 else -x
MOD = 1_000_000_007


class Solution:
    def maxPointsInsideSquare(self, points: List[List[int]], s: str) -> int:
        lst = list(
            sorted(
                (fmax(fabs(x), fabs(y)), ord(ch) - ord("a"))
                for (x, y), ch in zip(points, s)
            )
        )

        n, i, mask, ans = len(points), 0, 0, 0
        while i < n:
            j = i
            while i < n and lst[i][0] == lst[j][0]:
                if mask >> lst[i][1] & 1:
                    return ans
                mask |= 1 << lst[i][1]
                i += 1
            ans += i - j
        return ans
