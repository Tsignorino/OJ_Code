from typing import List


class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            cnt = 0
            maxV = 0
            while num:
                maxV = max(maxV, num % 10)
                num //= 10
                cnt += 1

            ans += int(str(maxV) * cnt)
        return ans
