from functools import cache


class Solution_1:
    def minimumOperations(self, num: str) -> int:
        n = len(num)

        @cache
        def dfs(i, cur) -> int:
            if i == n:
                return n if cur else 0
            r1 = dfs(i + 1, (cur * 10 + int(num[i])) % 25)
            r2 = dfs(i + 1, cur % 25) + 1
            return min(r1, r2)

        return dfs(0, 0)


class Solution_2:
    def minimumOperations(self, num: str) -> int:
        d = {"0": "05", "5": "27"}
        n = len(num)
        ans = n - 1 if "0" in num else n
        for i in range(n - 1, -1, -1):
            if num[i] in d:
                for j in range(i - 1, -1, -1):
                    if num[j] in d[num[i]]:
                        ans = min(ans, n - j - 2)
        return ans
