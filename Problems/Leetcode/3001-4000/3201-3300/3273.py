from functools import cmp_to_key
from typing import List


class Solution:
    def minDamage(self, power: int, damage: List[int], health: List[int]) -> int:
        n = len(damage)

        # 打敌人打到死
        # 类似 "切蛋糕"（3218, 3219, P3173）
        #
        # 交换论证一下
        # 造成的伤害 v1, v2，能够攻击的次数 c1, c2
        # c1 * (v1 + v2) + c2 * v2
        # c2 * (v1 + v2) + c1 * v1
        # 即, c1 * v2 和 c2 * v1
        a = [((health[i] + power - 1) // power, damage[i]) for i in range(n)]
        a.sort(key=cmp_to_key(lambda x, y: x[0] * y[1] - x[1] * y[0]))

        ans = s = 0
        for c, d in a:
            s += c
            ans += s * d
        return ans
