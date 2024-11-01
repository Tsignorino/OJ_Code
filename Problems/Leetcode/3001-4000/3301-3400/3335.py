class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        MOD = 10**9 + 7

        cnt = [0] * 26
        for v in s:
            cnt[ord(v) - ord("a")] += 1

        for _ in range(t):
            ncnt = [0] * 26
            for j in range(26):
                if j == 25:
                    ncnt[0] += cnt[j]
                    ncnt[1] += cnt[j]
                else:
                    ncnt[j + 1] = cnt[j]
            cnt = ncnt

        return sum(cnt) % MOD
