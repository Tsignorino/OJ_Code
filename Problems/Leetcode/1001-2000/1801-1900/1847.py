from math import inf
from typing import List

from sortedcontainers import SortedList


class Solution:
    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        rooms.sort(key=lambda r: r[1])
        q = len(queries)
        ans = [-1] * q
        roomsId = SortedList()
        j = len(rooms) - 1
        for i in sorted(range(q), key=lambda i: -queries[i][1]):
            pId, minSize = queries[i]
            while j >= 0 and rooms[j][1] >= minSize:
                roomsId.add(rooms[j][0])
                j -= 1

            diff = inf
            k = roomsId.bisect_left(pId)
            if k:
                diff = pId - roomsId[k - 1]
                ans[i] = roomsId[k - 1]
            if k < len(roomsId) and roomsId[k] - pId < diff:
                ans[i] = roomsId[k]
        return ans
