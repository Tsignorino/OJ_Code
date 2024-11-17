from collections import deque
from math import inf
from typing import List

fmax = lambda x, y: x if x > y else y
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]


class Solution:
    def minTimeToReach(self, t: List[List[int]]) -> int:
        n, m = len(t), len(t[0])

        dis = [[inf] * m for _ in range(n)]
        dis[0][0] = 0

        q = deque([(0, 0, 0)])
        while q:
            x, y, d = q.popleft()
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m:
                    nxt = fmax(d, t[nx][ny]) + 1
                    if nxt < dis[nx][ny]:
                        dis[nx][ny] = nxt
                        q.append((nx, ny, nxt))

        return int(dis[n - 1][m - 1])


# print(Solution().minTimeToReach([[0, 4], [4, 4]]))
