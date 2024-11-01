from collections import defaultdict
from typing import List


class Solution:
    def countPairs(self, nums: List[int]) -> int:
        ans = 0
        nums = sorted(nums, key=lambda x: len(str(x)))
        cnt = defaultdict(int)
        for x in nums:
            st = {x}  # set
            s = list(str(x))
            m = len(s)
            for i in range(m):  # 第一次交换
                for j in range(i + 1, m):
                    s[i], s[j] = s[j], s[i]
                    st.add(int("".join(s)))
                    for p in range(i + 1, m):  # 第二次交换
                        for q in range(p + 1, m):
                            s[p], s[q] = s[q], s[p]
                            st.add(int("".join(s)))
                            s[p], s[q] = s[q], s[p]
                    s[i], s[j] = s[j], s[i]
            ans += sum(cnt[x] for x in st)
            cnt[x] += 1
        return ans
