from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        stk = []

        def dfs(x: int):
            if x == len(graph) - 1:
                ans.append(stk.copy())
                return

            for y in graph[x]:
                stk.append(y)
                dfs(y)
                stk.pop()

        stk.append(0)
        dfs(0)

        return ans
