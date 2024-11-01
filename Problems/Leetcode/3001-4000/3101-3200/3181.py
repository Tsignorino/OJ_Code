from typing import List


class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        # f = 1
        # for v in sorted(set(rewardValues)):
        #     f |= (f & ((1 << v) - 1)) << v
        # return f.bit_length() - 1

        """
        优化：如果数组中包含 m-1, 或者两个不同元素之和等于 m-1, 可以直接返回 2m-1
        """
        m = max(rewardValues)
        s = set()
        for v in rewardValues:
            if v in s:
                continue
            if v == m - 1 or m - 1 - v in s:
                return m * 2 - 1
            s.add(v)

        f = 1
        for v in sorted(s):
            f |= (f & ((1 << v) - 1)) << v
        return f.bit_length() - 1
