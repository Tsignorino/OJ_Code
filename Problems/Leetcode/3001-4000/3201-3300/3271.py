from string import ascii_lowercase


class Solution:
    def stringHash(self, s: str, k: int) -> str:
        ans = []
        for i in range(0, len(s), k):
            ans.append(
                ascii_lowercase[
                    (sum(ord(ch) for ch in s[i : i + k]) - ord("a") * k) % 26
                ]
            )
        return "".join(ans)
