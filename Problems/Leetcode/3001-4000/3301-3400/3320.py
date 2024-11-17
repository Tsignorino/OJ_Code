from collections import Counter

mod = 10**9 + 7
d = dict(zip("FWE", range(3)))


class Solution:
    def countWinningSequences(self, s: str) -> int:
        v = [d[x] for x in s]

        tmp = [Counter() for _ in range(3)]
        for i in range(3):
            if i == v[0]:
                tmp[i][0] = 1
            elif (i - v[0]) % 3 == 1:
                tmp[i][1] = 1
            else:
                tmp[i][-1] = 1

        for i in range(1, len(v)):
            ntmp = [Counter() for _ in range(3)]
            for x in range(3):
                for y in range(3):
                    if y == x:
                        continue
                    for status in tmp[x]:
                        if y == v[i]:
                            ntmp[y][status] += tmp[x][status]
                            ntmp[y][status] %= mod
                        elif (y - v[i]) % 3 == 1:
                            ntmp[y][status + 1] += tmp[x][status]
                            ntmp[y][status + 1] %= mod
                        else:
                            ntmp[y][status - 1] += tmp[x][status]
                            ntmp[y][status - 1] %= mod
            tmp = ntmp

        ans = 0
        for i in range(3):
            for x in tmp[i]:
                if x > 0:
                    ans += tmp[i][x]
                    ans %= mod
        return ans
