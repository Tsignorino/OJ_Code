from itertools import permutations
from typing import List


class Solution:
    def maxGoodNumber(self, nums: List[int]) -> int:
        return max(
            int("".join(v), 2) for v in list(permutations([bin(v)[2:] for v in nums]))
        )
        return max(int(f"{x:b}{y:b}{z:b}", 2) for x, y, z in permutations(nums))


# print(list(permutations([2, 1, 3])))
