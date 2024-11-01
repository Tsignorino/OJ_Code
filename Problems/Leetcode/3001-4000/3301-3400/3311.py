from typing import List


class Solution:
    def constructGridLayout(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        deg = [-1] * 5
        for x, e in enumerate(g):
            deg[len(e)] = x

        """
        构造第一行
        """
        if deg[1] != -1:  # 只有一列
            row = [deg[1]]
        elif deg[4] == -1:  # 只有两列
            x = deg[2]
            for y in g[x]:
                if len(g[y]) == 2:
                    row = [x, y]
                    break
        else:
            x = deg[2]
            row = [x]
            pre = x
            x = g[x][0]
            while len(g[x]) == 3:
                row.append(x)
                for y in g[x]:
                    if y != pre and len(g[y]) < 4:
                        pre = x
                        x = y
                        break
            row.append(x)  # 此时 x 的度数为 2

        ans = [[] for _ in range(n // len(row))]
        ans[0] = row
        vis = [0] * n
        for x in row:
            vis[x] = 1
        for i in range(1, len(ans)):
            for x in ans[i - 1]:
                for y in g[x]:
                    if not vis[y]:
                        vis[y] = 1
                        ans[i].append(y)
                        break
        return ans
