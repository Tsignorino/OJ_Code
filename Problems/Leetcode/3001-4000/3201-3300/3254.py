from collections import deque
from typing import List


class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        q = deque()
        ans = []
        for i in range(n):
            while q and nums[q[-1]] + 1 != nums[i]:
                q.pop()
            q.append(i)
            if q[0] <= i - k:
                q.popleft()
            if i >= k - 1:
                ans.append(nums[q[-1]] if len(q) == k else -1)
        return ans
