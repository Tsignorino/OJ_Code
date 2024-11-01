from itertools import count
from math import isqrt, sqrt


class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:  # type: ignore
        """
        枚举
        """
        # cnt = [0, 0]
        # for i in count(1):
        #     cnt[i % 2] += i
        #     if (cnt[0] > red or cnt[1] > blue) and (cnt[0] > blue or cnt[1] > red):
        #         return i - 1

        """
        Math
        """

        def f(n: int, m: int) -> int:
            odd = isqrt(n)
            even = int((sqrt(m * 4 + 1) - 1) / 2)
            return even * 2 + 1 if odd > even else odd * 2

        return max(f(red, blue), f(blue, red))
