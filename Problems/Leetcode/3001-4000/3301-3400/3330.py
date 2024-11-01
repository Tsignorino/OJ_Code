from itertools import pairwise


class Solution:
    def possibleStringCount(self, word: str) -> int:
        n = len(word)
        ans = 1
        i = 0
        while i < n:
            j = i + 1
            while j < n and word[i] == word[j]:
                j += 1
            ans += j - i - 1
            i = j
        return ans

        """
        一行流
        """
        return 1 + sum(x == y for x, y in pairwise(word))
