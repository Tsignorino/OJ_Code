from typing import List


class Solution:
    def maxIceCream(self, costs: List[int], k: int) -> int:
        costs.sort()

        cnt = 0
        for cost in costs:
            if cost > k:
                break
            k -= cost
            cnt += 1
        return cnt
