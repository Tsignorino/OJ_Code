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

        return min(sum((x - 1) // (i * K + 1) + 1 for i, x in enumerate(s)) for s in permutations(strength))


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

(C++ 代码)

"""

from heapq import heappop, heappush
from typing import List, NamedTuple, Optional, Tuple, cast


class MCFGraph:
    class Edge(NamedTuple):
        src: int
        dst: int
        cap: int
        flow: int
        cost: int

    class _Edge:
        def __init__(self, dst: int, cap: int, cost: int) -> None:
            self.dst = dst
            self.cap = cap
            self.cost = cost
            self.rev: Optional[MCFGraph._Edge] = None

    def __init__(self, n: int) -> None:
        self._n = n
        self._g: List[List[MCFGraph._Edge]] = [[] for _ in range(n)]
        self._edges: List[MCFGraph._Edge] = []

    def addEdge(self, src: int, dst: int, cap: int, cost: int) -> int:
        assert 0 <= src < self._n
        assert 0 <= dst < self._n
        assert 0 <= cap
        m = len(self._edges)
        e = MCFGraph._Edge(dst, cap, cost)
        re = MCFGraph._Edge(src, 0, -cost)  # 初始容量为 0，权值为负
        e.rev, re.rev = re, e
        self._g[src].append(e)
        self._g[dst].append(re)
        self._edges.append(e)
        return m

    def getEdge(self, i: int) -> Edge:
        assert 0 <= i < len(self._edges)
        e = self._edges[i]
        re = cast(MCFGraph._Edge, e.rev)
        return MCFGraph.Edge(re.dst, e.dst, e.cap + re.cap, re.cap, e.cost)

    def edges(self) -> List[Edge]:
        return [self.getEdge(i) for i in range(len(self._edges))]

    def flow(self, s: int, t: int, flow_limit: Optional[int] = None) -> Tuple[int, int]:
        """
        计算从源点 s 到汇点 t 的最大流量，直到达到 flow_limit。
        """
        return self.slope(s, t, flow_limit)[-1]

    def slope(self, s: int, t: int, flow_limit: Optional[int] = None) -> List[Tuple[int, int]]:
        """
        返回一系列 (flow, cost) 对，表示在不同流量水平下的总费用
        """
        assert 0 <= s < self._n
        assert 0 <= t < self._n
        assert s != t
        if flow_limit is None:
            flow_limit = cast(int, sum(e.cap for e in self._g[s]))  # 默认为源点出发的所有边的容量之和

        dual = [0] * self._n
        prev: List[Optional[Tuple[int, MCFGraph._Edge]]] = [None] * self._n

        def refine_dual() -> bool:
            """
            更新对偶变量
            """
            pq = [(0, s)]
            visited = [False] * self._n
            dist: List[Optional[int]] = [None] * self._n
            dist[s] = 0
            while pq:
                dist_v, v = heappop(pq)
                if visited[v]:
                    continue
                visited[v] = True
                if v == t:
                    break
                dual_v = dual[v]
                for e in self._g[v]:
                    w = e.dst
                    if visited[w] or e.cap == 0:
                        continue
                    reduced_cost = e.cost - dual[w] + dual_v
                    new_dist = dist_v + reduced_cost
                    dist_w = dist[w]
                    if dist_w is None or new_dist < dist_w:
                        dist[w] = new_dist
                        prev[w] = v, e
                        heappush(pq, (new_dist, w))
            else:
                return False
            dist_t = dist[t]
            for v in range(self._n):
                if visited[v]:
                    dual[v] -= cast(int, dist_t) - cast(int, dist[v])
            return True

        flow = 0
        cost = 0
        prev_cost_per_flow: Optional[int] = None
        result = [(flow, cost)]
        while flow < flow_limit:
            if not refine_dual():  # 没有找到增广路径
                break
            f = flow_limit - flow
            v = t
            while prev[v] is not None:
                u, e = cast(Tuple[int, MCFGraph._Edge], prev[v])
                f = min(f, e.cap)
                v = u
            v = t
            while prev[v] is not None:
                u, e = cast(Tuple[int, MCFGraph._Edge], prev[v])
                e.cap -= f
                assert e.rev is not None
                e.rev.cap += f
                v = u
            c = -dual[s]
            flow += f
            cost += f * c
            if c == prev_cost_per_flow:
                result.pop()
            result.append((flow, cost))
            prev_cost_per_flow = c
        return result


class Solution:
    def findMinimumTime(self, a: List[int], k: int) -> int:
        n = len(a)
        s = n * 2
        t = s + 1
        g = MCFGraph(t + 1)

        for i in range(n):
            g.add_edge(s, i, 1, 0)
            g.add_edge(i + n, t, 1, 0)
            for j in range(n):
                g.add_edge(i, j + n, 1, (a[i] - 1) // (k * j + 1) + 1)

        return g.flow(s, t, n * k)[1]


print(Solution().findMinimumTime(strength=[2, 5, 4], K=2))
