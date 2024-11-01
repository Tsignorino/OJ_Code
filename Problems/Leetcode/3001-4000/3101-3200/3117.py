from functools import cache
from typing import List

# collections  sortedcontainers  more_itertools

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

MOD = 1_000_000_007


class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        inf = 1_000_000_007
        n, m = len(nums), len(andValues)

        @cache
        def dfs(i: int, j: int, and_: int) -> int:
            if n - i < m - j:
                return inf
            if j == m:
                return 0 if i == n else inf

            and_ &= nums[i]
            res = dfs(i + 1, j, and_)
            if and_ == andValues[j]:
                res = fmin(res, dfs(i + 1, j + 1, -1) + nums[i])
            return res

        ans = dfs(0, 0, -1)
        dfs.cache_clear()
        return ans if ans < inf else -1
