MOD = 1_000_000_007
MX = 1001

s = [[0] * MX for _ in range(MX)]
s[0][0] = 1
for i in range(1, MX):
    for j in range(1, i + 1):
        s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % MOD


class Solution:
    def numberOfWays(self, n: int, x: int, y: int) -> int:
        ans = 0
        perm = p = 1
        for i in range(1, min(n, x) + 1):
            perm = perm * (x + 1 - i) % MOD
            p = p * y % MOD
            ans += perm * s[n][i] * p
            ans %= MOD
        return ans
