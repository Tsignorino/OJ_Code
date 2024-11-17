from heapq import heapify, heappop, heappush
from math import inf
from typing import List

fmax = lambda x, y: x if x > y else y
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]


class Solution:
    def minTimeToReach(self, t: List[List[int]]) -> int:
        n, m = len(t), len(t[0])

        dis = [[inf] * m for _ in range(n)]
        dis[0][0] = 0

        q = [(dis[0][0], 0, 0)]
        heapify(q)
        while q:
            d, x, y = heappop(q)
            if d > dis[x][y]:
                continue
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m:
                    nxt = fmax(d, t[nx][ny]) + (x + y) % 2 + 1
                    if nxt < dis[nx][ny]:
                        dis[nx][ny] = nxt
                        heappush(q, (nxt, nx, ny))

        return int(dis[n - 1][m - 1])


# print(Solution().minTimeToReach([[0, 58], [27, 69]]))
# print(Solution().minTimeToReach([[0, 0, 0, 0], [0, 0, 0, 0]]))
# print(Solution().minTimeToReach([[25, 44], [4, 2]]))
