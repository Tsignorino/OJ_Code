from typing import List


class Solution:
    def countPairs(self, nums: List[int]) -> int:
        n = len(nums)

        def check(i: int, j: int) -> bool:
            if nums[i] == nums[j]:
                return True

            s, t = list(str(nums[i])), list(str(nums[j]))
            if len(s) <= len(t):
                s, t = t, s

            m = len(s)
            for p in range(m):
                for q in range(p + 1, m):
                    s[p], s[q] = s[q], s[p]
                    if int("".join(s)) == int("".join(t)):
                        return True
                    s[p], s[q] = s[q], s[p]
            return False

        cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                cnt += check(i, j)
        return cnt
