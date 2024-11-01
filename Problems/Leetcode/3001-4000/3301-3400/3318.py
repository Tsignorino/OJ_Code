from typing import Counter, List


class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        ans = []
        for i in range(len(nums) - k + 1):
            lst = [(v, c) for v, c in Counter(nums[i : i + k]).items()]
            lst.sort(key=lambda x: (-x[1], -x[0]))
            ans.append(sum(x * y for x, y in lst[:x]))
        return ans
