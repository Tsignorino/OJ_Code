# Date: 2024-12-20  星期五

import sys
from typing import List

input = lambda: sys.stdin.readline().strip()

I = lambda: input()
II = lambda: int(input())
FI = lambda: float(input())
LFI = lambda: list(map(float, input().split()))
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MI = lambda: map(int, input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

MOD = 1_000_000_007


def multiply(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    return [[sum(x * y for x, y in zip(row, col)) % MOD for col in zip(*b)] for row in a]


# a^n @ f，其中 @ 是矩阵乘法，f 为列向量
def qpow_mul(a: List[List[int]], b: int, f: List[List[int]] = -1) -> List[List[int]]:
    n = len(a)
    if f == -1:
        f = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    while b:
        if b & 1:
            f = multiply(a, f)
        a = multiply(a, a)
        b >>= 1
    return f


def solve():
    n = II()
    if n <= 3:
        print(1)
        return

    a = [[1] for _ in range(3)]
    mul = [[0, 1, 0], [0, 0, 1], [1, 0, 1]]
    print(qpow_mul(mul, n - 3, a)[-1][0])


if __name__ == "__main__":
    for _ in range(II()):
        solve()
