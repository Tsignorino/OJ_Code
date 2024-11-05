from collections import Counter, defaultdict
from math import isqrt


# class Solution:
#     def judgeSquareSum(self, c: int) -> bool:
#         a, b = 0, isqrt(c)
#         while a <= b:
#             s = a * a + b * b
#             if s == c:
#                 return True
#             if s < c:
#                 a += 1
#             else:
#                 b -= 1
#         return False


class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        d = Counter()
        for i in range(2, isqrt(c) + 1):
            while c % i == 0:
                c //= i
                d[i] += 1
        if c > 1:
            d[c] += 1
        return not any(v % 4 == 3 and c % 2 == 1 for v, c in d.items())
