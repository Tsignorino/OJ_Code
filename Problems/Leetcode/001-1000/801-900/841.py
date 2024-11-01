from collections import deque
from typing import List


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        vis = [0] * n
        q = deque()
        q.append(0)
        vis[0] = 1
        while q:
            t = q.popleft()
            for v in rooms[t]:
                if not vis[v]:
                    q.append(v)
                    vis[v] = 1
        return sum(vis) == n
