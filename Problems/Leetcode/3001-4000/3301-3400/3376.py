from functools import cache
from itertools import permutations
from math import inf
from typing import List


class Solution:
    def findMinimumTime(self, strength: List[int], k: int) -> int:
        """
        手写排列，回溯
        """
        n = len(strength)
        ans = inf
        done = [False] * n

        def dfs(i: int, time: int) -> None:
            nonlocal ans
            if time >= ans:  # 最优性剪枝：答案不可能变小
                return
            if i == n:
                ans = time
                return
            x = 1 + i * k
            for j, s in enumerate(strength):
                if not done[j]:
                    done[j] = True
                    dfs(i + 1, time + (s - 1) // x + 1)
                    done[j] = False

        dfs(0, 0)
        return ans


class Solution:
    def findMinimumTime(self, strength: List[int], K: int) -> int:
        """
        排列
        """

        def needTime(li):
            x, t = 1, 0
            for v in li:
                t += (v + x - 1) // x
                x += K
            return t

        return min(needTime(li) for li in permutations(strength))


class Solution:
    def findMinimumTime(self, strength: List[int], K: int) -> int:
        """
        状压 DP
        """
        n = len(strength)

        @cache
        def dfs(i: int) -> int:
            if i == 0:
                return 0
            x = 1 + K * (n - i.bit_count())
            return min(dfs(i ^ (1 << j)) + (s + x - 1) // x for j, s in enumerate(strength) if i >> j & 1)

        return dfs((1 << n) - 1)


class Solution:
    def findMinimumTime(self, strength: List[int], K: int) -> int:
        """
        递推
        """
        n = len(strength)
        f = [0] * (1 << n)
        for i in range(1, 1 << n):
            x = 1 + K * (n - i.bit_count())
            f[i] = min(f[i ^ (1 << j)] + (s + x - 1) // x for j, s in enumerate(strength) if i >> j & 1)
        return f[-1]


"""

n 如果更大呢？

创建一个二分图：
    左部为锁的编号 i=0,1,2,...,n-1 
    右部表示这个锁是第 j=0,1,2,…,n-1 次开的。
问题相当于计算这个二分图的最大带权匹配。

建图：
    从 i 向 j 连边, 容量为 1, 费用为 strength[i] / (1 + k * j) （上取整）
    从超级源点 S=2n 向每个 i 连边, 容量为 1, 费用 0。
    从每个 j 向超级汇点 T=2n+1 连边, 容量为 1, 费用为 0。
计算从 S 到 T 的最小费用流，即为答案。

（见 C++ 代码）

"""


print(Solution().findMinimumTime(strength=[2, 5, 4], K=2))
