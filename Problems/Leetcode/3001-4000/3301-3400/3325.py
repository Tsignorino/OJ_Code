from collections import defaultdict


class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        ans = 0
        cnt = defaultdict(int)
        l = 0
        for ch in s:
            cnt[ch] += 1
            while cnt[ch] >= k:
                cnt[s[l]] -= 1
                l += 1
            ans += l
        return ans
