from collections import deque
import queue
from typing import List


class Solution:
    def validPath(
        self, n: int, edges: List[List[int]], source: int, destination: int
    ) -> bool:
        g = [[] for i in range(n)]
        for edge in edges:
            g[edge[0]].append(edge[1])
            g[edge[1]].append(edge[0])

        """
        DFS
        """

        def dfs(x: int):
            if x == destination:
                return True
            vis[x] = True
            for y in g[x]:
                if not vis[y] and dfs(y):
                    return True
            return False

        vis = [False] * n
        return dfs(source)

        """
        BFS 图中存在环，不要将节点加入到队列后再标记
        """
        # vis = [False] * n
        # q = deque()  # q = queue.Queue()  # ! Queue() 需要导入 queue
        # q.append(source)  # q.put(source)
        # vis[source] = True
        # while q:  # while not q.empty():
        #     t = q.popleft()  # t = q.get()
        #     if t == destination:
        #         break
        #     for v in g[t]:
        #         if not vis[v]:
        #             q.append(v)  # q.put(v)
        #             vis[v] = True
        # return vis[destination]

        """
        并查集
        """
        # pa = list(range(n))

        # def find(x: int):
        #     if pa[x] != x:
        #       pa[x] = find(pa[x])
        #     return pa[x]

        # for edge in edges:
        #     px, py = find(edge[0]), find(edge[1])
        #     if px == py:
        #         continue
        #     pa[px] = py

        # return find(source) == find(destination)
