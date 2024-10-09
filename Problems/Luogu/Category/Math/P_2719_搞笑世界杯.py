from math import comb

n = int(input())

"""
Math
"""
# print(f"{1 - comb(n - 2, n // 2 - 1) / pow(2,  n - 2):.4f}")

"""
DP
"""
n //= 2
f = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(2, n + 1):
    f[i][0] = f[0][i] = 1
for i in range(1, n + 1):
    for j in range(1, n + 1):
        f[i][j] = f[i - 1][j] / 2 + f[i][j - 1] / 2  # type: ignore
print(f"{f[n][n]:.4f}")
