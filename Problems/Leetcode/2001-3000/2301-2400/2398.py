from collections import deque
from itertools import accumulate
from typing import List

fmax = lambda x, y: x if x >= y else y

"""

尝试一下 二分 + 定长滑窗

"""


class Solution:
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        n = len(chargeTimes)

        pre = list(accumulate(runningCosts, initial=0))

        def check(x: int) -> bool:
            q = deque()

            for r in range(n):
                while q and chargeTimes[r] >= chargeTimes[q[-1]]:
                    q.pop()

                while q and q[0] < r - x + 1:
                    q.popleft()

                q.append(r)

                if r + 1 >= x and (pre[r + 1] - pre[fmax(r - x + 1, 0)]) * x + chargeTimes[q[0]] <= budget:
                    return True

            return False

        lo, hi = 0, n + 1
        while lo + 1 < hi:
            mid = lo + (hi - lo) // 2

            if check(mid):
                lo = mid
            else:
                hi = mid
        return lo


# print(Solution().maximumRobots([3, 6, 1, 3, 4], [2, 1, 3, 4, 5], 25))
# print(Solution().maximumRobots([11, 12, 19], [10, 8, 7], 19))
print(
    Solution().maximumRobots(
        [8, 76, 74, 9, 75, 71, 71, 42, 15, 58, 88, 38, 56, 59, 10, 11],
        [1, 92, 41, 63, 22, 37, 37, 8, 68, 97, 39, 59, 45, 50, 29, 37],
        412,
    )
)
