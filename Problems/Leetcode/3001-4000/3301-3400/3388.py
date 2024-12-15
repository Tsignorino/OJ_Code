from typing import List


def zfunc(s: List[int]) -> List[int]:
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(z[i - l], r - i + 1)
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            l, r = i, i + z[i]
            z[i] += 1
    return z


class Solution:
    def beautifulSplits(self, nums: List[int]) -> int:
        n = len(nums)
        Z = zfunc(nums)
        ans = 0
        for i in range(1, n - 1):
            z = zfunc(nums[i:])
            for j in range(i + 1, n):
                if i <= j - i and Z[i] >= i or j - i <= n - j and z[j - i] >= j - i:
                    ans += 1
        return ans


print(Solution().beautifulSplits(nums=[1, 1, 2, 1]))
