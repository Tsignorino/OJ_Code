from typing import List


class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        """
        并查集
        """
        pa = list(range(n - 1))

        def find(x: int) -> int:
            root = x
            while pa[root] != root:
                root = pa[root]
            while pa[x] != root:
                pa[x], x = root, pa[x]
            return root

        ans = []
        cnt = n - 1
        for l, r in queries:
            pr = find(r - 1)
            i = find(l)
            while i < r - 1:
                cnt -= 1
                pa[i] = pr
                i = find(i + 1)
            ans.append(cnt)
        return ans

    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        """
        记录跳转位置
        """
        ans = []
        nxt = list(range(1, n))
        cnt = n - 1
        for i, r in queries:
            while nxt[i] < r:
                cnt -= 1
                nxt[i], i = r, nxt[i]
            ans.append(cnt)
        return ans
