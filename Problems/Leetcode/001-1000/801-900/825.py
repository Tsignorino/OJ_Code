from typing import List


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        d = [0] * 121
        for v in ages:
            d[v] += 1

        ans = cnt = y = 0
        for x, c in enumerate(d):
            cnt += c
            if y * 2 <= x + 14:
                cnt -= d[y]
                y += 1
            if cnt:
                ans += c * cnt - c
        return ans
