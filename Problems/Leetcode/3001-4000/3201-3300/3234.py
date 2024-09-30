from typing import List

fmax = lambda x, y: x if x > y else y
MOD = 1_000_000_007


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        ids = [i for i, ch in enumerate(s) if ch == "0"]
        tot = n - len(ids)  # 1 的个数
        ids.append(n)  # 哨兵

        ans = 0
        start = 0  # 左端点
        for i, ch in enumerate(s):
            for k in range(start, len(ids) - 1):  # 枚举左端点后续的 0
                c0 = k - start + 1
                if c0 * c0 > tot:
                    break
                c1 = ids[k] - i + 1 - c0
                ans += fmax(ids[k + 1] - ids[k] - fmax(c0 * c0 - c1, 0), 0)

            if ch == "0":
                start += 1
            else:
                ans += ids[start] - i
                tot -= 1
        return ans
