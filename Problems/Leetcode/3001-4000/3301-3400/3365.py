class Solution:
    def isPossibleToRearrange(self, s: str, t: str, k: int) -> bool:
        n = len(s)
        k = n // k
        a = sorted(s[i : i + k] for i in range(0, n, k))
        b = sorted(t[i : i + k] for i in range(0, n, k))
        return a == b
