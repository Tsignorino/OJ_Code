from functools import reduce
from itertools import count
from operator import mul


class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        for i in count(n):
            # tmp = i
            # prod = 1
            # while tmp:
            #     prod *= tmp % 10
            #     tmp //= 10
            prod = reduce(mul, map(int, str(i)))
            if prod % t == 0:
                return i
        return n

        return next(i for i in count(n) if eval("*".join(map(str, str(i)))) % t == 0)
