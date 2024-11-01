from functools import cache


@cache
def dfs(i: int) -> int:
    if i == 0:
        return 0
    return min(max(j, dfs(i - j) + 1) for j in range(1, i + 1))


class Solution:
    def twoEggDrop(self, n: int) -> int:
        """
        DP
        """
        return dfs(n)

        """
        Math
        """
        # return ceil(sqrt(n * 8 + 1)) // 2
