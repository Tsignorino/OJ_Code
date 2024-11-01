from collections import defaultdict
from typing import List


class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        g = [[] for _ in range(n)]
        for i in range(1, n):
            g[parent[i]].append(i)

        # 维护每个字符的祖先节点
        """
        一次 DFS
        """
        ans = [1] * n
        ch = defaultdict(lambda: -1)

        def dfs(x: int):
            pre = ch[s[x]]
            ch[s[x]] = x
            for y in g[x]:
                dfs(y)
                res = ch[s[y]]
                ans[x if res < 0 else res] += ans[y]
            ch[s[x]] = pre

        dfs(0)
        return ans

        """
        两次 DFS
        """
        ch = [-1] * 26

        def rebuild(x: int):
            idx = ord(s[x]) - ord("a")
            pre = ch[idx]
            ch[idx] = x
            for i in range(len(g[x])):
                y = g[x][i]
                pa = ch[ord(s[y]) - ord("a")]
                if pa != -1:
                    g[pa].append(y)
                    g[x][i] = -1
                rebuild(y)
            ch[idx] = pre

        rebuild(0)

        ans = [1] * n

        def dfs(x: int):
            for y in g[x]:
                if y != -1:
                    dfs(y)
                    ans[x] += ans[y]

        dfs(0)
        return ans
