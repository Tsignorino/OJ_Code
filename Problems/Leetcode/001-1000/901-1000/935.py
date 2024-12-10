from functools import cache
from typing import List

"""
按 j 分类，优化状态转移

https://leetcode.cn/problems/knight-dialer/solutions/3004116/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-x06l
"""

MOD = 1_000_000_007


@cache
def dfs(i: int, j: int) -> int:
    if i == 0:
        return 1
    if j == 0:
        return (dfs(i - 1, 1) + dfs(i - 1, 2)) % MOD
    if j == 1:
        return dfs(i - 1, 0) * 2 % MOD
    if j == 2:
        return (dfs(i - 1, 0) * 2 + dfs(i - 1, 3)) % MOD
    return dfs(i - 1, 2) * 2 % MOD


class Solution:
    def knightDialer(self, n: int) -> int:
        if n == 1:
            return 10
        return (dfs(n - 1, 0) * 4 + dfs(n - 1, 1) * 2 + dfs(n - 1, 2) * 2 + dfs(n - 1, 3)) % MOD


"""
矩阵快速幂
"""

MOD = 1_000_000_007


# a @ b，其中 @ 是矩阵乘法
def multiply(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    return [[sum(x * y for x, y in zip(row, col)) % MOD for col in zip(*b)] for row in a]


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
    def knightDialer(self, n: int) -> int:
        if n == 1:
            return 10
        f0 = [[1] for _ in range(4)]
        a = [[0, 1, 1, 0], [2, 0, 0, 0], [2, 0, 0, 1], [0, 0, 2, 0]]
        a = qpow_mul(a, n - 1, f0)
        return (a[0][0] * 4 + a[1][0] * 2 + a[2][0] * 2 + a[3][0]) % MOD
