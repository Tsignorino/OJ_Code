from functools import cache
from typing import List


class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        d = set(dictionary)

        @cache
        def dfs(i: int) -> int:
            if i < 0:
                return 0

            res = dfs(i - 1) + 1
            for j in range(i + 1):
                if s[j : i + 1] in d:
                    res = min(res, dfs(j - 1))
            return res

        return dfs(len(s) - 1)
