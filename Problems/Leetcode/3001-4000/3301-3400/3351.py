from collections import defaultdict
from typing import Any, Counter, Optional, List

# 子序列计数 DP
# https://leetcode.cn/circle/discuss/tXLS3i/
# 动态规划题单 $7.2

"""
class Solution:
    def sumOfGoodSubsequences(self, nums: List[int]) -> int:
        MOD = 1_000_000_007
        c = defaultdict(int)
        s = defaultdict(int)

        for v in nums:
            c[v] += c[v - 1] + c[v + 1] + 1
            s[v] += s[v - 1] + (c[v - 1] * v) + s[v + 1] + (c[v + 1] * v) + v
            s[v] %= MOD
        return sum(s.values()) % MOD
"""


class Solution:
    def sumOfGoodSubsequences(self, nums: List[int]) -> int:
        """
        用数组代替哈希表
        """
        MOD = 1_000_000_007
        mx = max(nums) + 2
        f = [0] * mx
        cnt = [0] * mx
        for x in nums:
            c = cnt[x - 1] + cnt[x + 1] + 1
            f[x] = (f[x] + f[x - 1] + f[x + 1] + x * c) % MOD
            cnt[x] = (cnt[x] + c) % MOD
        return sum(f) % MOD


# print(Solution().sumOfGoodSubsequences([1, 2, 1]))
# print(Solution().sumOfGoodSubsequences([3, 4, 5]))
print(Solution().sumOfGoodSubsequences([0, 1]))
