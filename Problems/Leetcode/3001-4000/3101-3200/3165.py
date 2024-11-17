if 1:
    from collections import Counter
    from functools import cache
    from heapq import heapify, heappop, heappushpop
    from itertools import permutations
    from math import comb, inf
    from typing import Any, List, Optional

    from more_itertools import minmax, sieve

lowbit = lambda x: x & -x

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

MOD = 1_000_000_007


class Solution:
    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)

        t = [[0] * 4 for _ in range(2 << n.bit_length())]

        def pull(o: int):
            a, b = t[o << 1], t[o << 1 | 1]
            t[o][0] = fmax(a[0] + b[2], a[1] + b[0])
            t[o][1] = fmax(a[0] + b[3], a[1] + b[1])
            t[o][2] = fmax(a[2] + b[2], a[3] + b[0])
            t[o][3] = fmax(a[2] + b[3], a[3] + b[1])

        def build(o: int, l: int, r: int):
            if l == r:
                t[o][3] = fmax(nums[l], 0)
                return
            m = (l + r) // 2
            build(o << 1, l, m)
            build(o << 1 | 1, m + 1, r)
            pull(o)

        def modify(o: int, l: int, r: int, i: int, val: int):
            if l == r:
                t[o][3] = fmax(val, 0)
                return
            m = (l + r) // 2
            if i <= m:
                modify(o << 1, l, m, i, val)
            else:
                modify(o << 1 | 1, m + 1, r, i, val)
            pull(o)

        build(1, 0, n - 1)

        ans = 0
        for i, x in queries:
            modify(1, 0, n - 1, i, x)
            ans += t[1][3]
        return ans % MOD
