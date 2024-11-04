from functools import cache
from typing import List


class Solution:
    def shoppingOffers(
        self, price: List[int], special: List[List[int]], needs: List[int]
    ) -> int:
        n = len(needs)

        pack = []
        for v in special:
            if (
                sum(v[i] for i in range(n))
                and sum(v[i] * price[i] for i in range(n)) > v[-1]
            ):
                pack.append(v)

        @cache
        def dfs(needs):
            cost = sum(needs[i] * price[i] for i in range(n))
            for v in pack:
                new_needs = list(needs)
                ok = 1
                for j in range(n):
                    if v[j] > new_needs[j]:
                        ok = 0
                        break
                    new_needs[j] -= v[j]
                if ok:
                    cost = min(cost, dfs(tuple(new_needs)) + v[n])
            return cost

        return dfs(tuple(needs))
