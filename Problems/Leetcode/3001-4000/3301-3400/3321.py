from collections import Counter
from typing import List
from sortedcontainers import SortedList


class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        cnt = Counter()
        for v in nums:
            cnt[v] = 0
        for v in nums[:k]:
            cnt[v] += 1

        tmp = sorted((cnt[x], x) for x in cnt)
        stl1 = SortedList(tmp[:-x])
        stl2 = SortedList(tmp[-x:])

        ans = []
        res = sum(x * y for x, y in stl2)
        ans.append(res)

        for i in range(len(nums) - k):
            if (cnt[nums[i]], nums[i]) in stl1:
                stl1.remove((cnt[nums[i]], nums[i]))
            else:
                stl2.remove((cnt[nums[i]], nums[i]))
                res -= cnt[nums[i]] * nums[i]
            cnt[nums[i]] -= 1
            stl1.add((cnt[nums[i]], nums[i]))

            i += k

            if (cnt[nums[i]], nums[i]) in stl1:
                stl1.remove((cnt[nums[i]], nums[i]))
            else:
                stl2.remove((cnt[nums[i]], nums[i]))
                res -= cnt[nums[i]] * nums[i]
            cnt[nums[i]] += 1
            stl1.add((cnt[nums[i]], nums[i]))

            while stl1 and (len(stl2) < x or stl1[-1] > stl2[0]):
                v = stl1.pop()
                res += v[0] * v[1]
                stl2.add(v)

            while len(stl2) > x:
                v = stl2.pop(0)
                res -= v[0] * v[1]
                stl1.add(v)

            ans.append(res)

        return ans
