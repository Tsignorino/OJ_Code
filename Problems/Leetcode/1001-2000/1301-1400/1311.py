from collections import defaultdict, deque
from typing import List


class Solution:
    def watchedVideosByFriends(
        self,
        watchedVideos: List[List[str]],
        friends: List[List[int]],
        id: int,
        level: int,
    ) -> List[str]:
        n = len(watchedVideos)
        vis = [0] * n
        q = deque([id])
        vis[id] = 1
        for _ in range(level):
            s = len(q)
            for i in range(s):
                u = q.popleft()
                for v in friends[u]:
                    if not vis[v]:
                        q.append(v)
                        vis[v] = 1

        c = defaultdict(int)
        for v in q:
            for ch in watchedVideos[v]:
                c[ch] += 1

        return [v[0] for v in sorted(list(c.items()), key=lambda x: (x[1], x[0]))]


s = Solution()
watchedVideos = [["A", "B"], ["C"], ["B", "C"], ["D"]]
friends = [[1, 2], [0, 3], [0, 3], [1, 2]]
s.watchedVideosByFriends(watchedVideos, friends, 0, 1)
