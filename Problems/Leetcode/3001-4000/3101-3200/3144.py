from collections import defaultdict
from functools import cache
from math import inf


class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i < 0:
                return 0
            res = inf
            cnt = defaultdict(int)
            mx = 0
            for j in range(i, -1, -1):
                cnt[s[j]] += 1
                if cnt[s[j]] > mx:
                    mx = cnt[s[j]]
                if i - j + 1 == len(cnt) * mx:
                    r = dfs(j - 1) + 1
                    if r < res:
                        res = r
            return res  # type: ignore

        return dfs(len(s) - 1)
