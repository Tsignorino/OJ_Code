from bisect import bisect_left
from typing import List


class Solution:
    def countKConstraintSubstrings(self, s: str, k: int, queries: List[List[int]]) -> List[int]:
        n = len(s)
        left = [0] * n
        pre = [0] * (n + 1)
        cnt = [0, 0]
        l = 0
        for i, r in enumerate(s):
            cnt[ord(r) & 1] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[ord(s[l]) & 1] -= 1
                l += 1
            left[i] = l
            pre[i + 1] = pre[i] + i - l + 1

        ans = []
        for l, r in queries:
            j = bisect_left(left, l, l, r + 1)
            ans.append(pre[r + 1] - pre[j] + (j - l + 1) * (j - l) // 2)
        return ans
