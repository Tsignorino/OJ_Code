from math import inf
from typing import List


class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        xor, in_, out, clk = [0] * n, [0] * n, [0] * n, 0

        def dfs(x: int, pa: int) -> None:
            nonlocal clk
            clk += 1
            in_[x] = clk
            xor[x] = nums[x]
            for y in g[x]:
                if y != pa:
                    dfs(y, x)
                    xor[x] ^= xor[y]
            out[x] = clk

        dfs(0, -1)

        ans = inf
        for i in range(2, n):
            for j in range(1, i):
                if in_[i] < in_[j] <= out[i]:
                    x, y, z = xor[j], xor[i] ^ xor[j], xor[0] ^ xor[i]
                elif in_[j] < in_[i] <= out[j]:
                    x, y, z = xor[i], xor[i] ^ xor[j], xor[0] ^ xor[j]
                else:
                    x, y, z = xor[i], xor[j], xor[0] ^ xor[i] ^ xor[j]
                ans = min(ans, max(x, y, z) - min(x, y, z))
                if ans == 0:
                    return 0
        return ans  # type: ignore
