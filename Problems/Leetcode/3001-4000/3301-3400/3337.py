if 1:
    from typing import Any, Optional, List
    from collections import Counter
    from functools import cache
    from heapq import heapify, heappop, heappushpop
    from itertools import permutations
    from math import comb, inf
    from more_itertools import minmax, sieve

    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    lowbit = lambda x: x & -x

MOD = 1_000_000_007


# a @ b，其中 @ 是矩阵乘法
def multiply(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    return [
        [sum(x * y for x, y in zip(row, col)) % MOD for col in zip(*b)] for row in a
    ]


# a^n @ f0
def qpow_mul(a: List[List[int]], b: int, f: List[List[int]]) -> List[List[int]]:
    res = f
    while b:
        if b & 1:
            res = multiply(a, res)
        a = multiply(a, a)
        b >>= 1
    return res


class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        N = 26
        f = [[1] for _ in range(N)]
        m = [[0] * N for _ in range(N)]
        for i, c in enumerate(nums):
            for j in range(i + 1, i + c + 1):
                m[i][j % N] = 1
        m = qpow_mul(m, t, f)

        ans = 0
        for ch, cnt in Counter(s).items():
            ans += m[ord(ch) - ord("a")][0] * cnt
        return ans % MOD
