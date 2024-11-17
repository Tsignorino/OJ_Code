from functools import cache
from itertools import accumulate
from math import inf
from typing import Any, List, Optional

from more_itertools import minmax, sieve

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

MOD = 1_000_000_007


class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        diff = [1 if nums[i] - nums[i - 1] > 0 else 0 for i in range(1, n)]
        acc = list(accumulate(diff, initial=0))
        for i in range(n + 1):
            if i + 2 * k - 1 >= len(acc):
                break
            if acc[i + k - 1] - acc[i] == k - 1 and acc[i + 2 * k - 1] - acc[i + k] == k - 1:
                return True
        return False


class mySolution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        for i in range(n - 1):
            ok = 1
            for j in range(i, i + k - 1):
                if j >= n - 1 or nums[j + 1] <= nums[j]:
                    ok = 0
                    break
            for j in range(i + k, i + k + k - 1):
                if j >= n - 1 or nums[j + 1] <= nums[j]:
                    ok = 0
                    i += k
                    break
            if ok:
                return True
        return False

        return any(
            all(nums[i + j] < nums[i + j + 1] for j in range(k - 1))
            and all(nums[i + k + j] < nums[i + k + j + 1] for j in range(k - 1))
            for i in range(len(nums) - 2 * k + 1)
        )


print(Solution().hasIncreasingSubarrays(nums=[1, 2, 3, 4, 4, 4, 4, 5, 6, 7], k=5))
