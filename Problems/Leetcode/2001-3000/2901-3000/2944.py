from collections import deque
from functools import cache
from typing import List


class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)

        """         
        @cache
        def dfs(i: int) -> int:
            if i * 2 >= n:
                return prices[i - 1]
            # 买了第 i 个，[i+1, 2i] 都是免费的，枚举下次需要购买的范围 [i+1, 2i+1]
            return min(dfs(j) for j in range(i + 1, i * 2 + 2)) + prices[i - 1]

        return dfs(1)
        """

        # 递推
        """ 
        for i in range((n + 1) // 2 - 1, 0, -1):
            prices[i - 1] += min(prices[i : i * 2 + 1])
        return prices[0]
        """

        # 单调队列优化
        n = len(prices)
        q = deque([(n + 1, 0)])
        for i in range(n, 0, -1):
            while q[-1][0] > i * 2 + 1:
                q.pop()

            f = prices[i - 1] + q[-1][1]
            while f <= q[0][1]:
                q.popleft()

            q.appendleft((i, f))
        return q[0][1]
