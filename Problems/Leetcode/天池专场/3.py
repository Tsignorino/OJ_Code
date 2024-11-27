from collections import Counter, defaultdict
from typing import List


class Solution:
    def arrangeBookshelf(self, order: List[int], limit: int) -> List[int]:
        # 单调栈：整体思路，如果找到更小的元素，就把前面更大的元素去掉
        # 如果元素出现次数大于 limit，要进行删除，且必须剩下 limit 个
        left = Counter(order)
        cnt = defaultdict(int)
        st = [0]  # 哨兵
        for x in order:
            if cnt[x] == limit:  # 个数已经足够，更新 left 即可
                left[x] -= 1
                continue
            while x < st[-1] and left[st[-1]] > limit:
                left[st[-1]] -= 1
                cnt[st[-1]] -= 1
                st.pop()
            cnt[x] += 1
            st.append(x)
        return st[1:]
