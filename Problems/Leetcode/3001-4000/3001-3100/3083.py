from itertools import pairwise


class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        """
        ss = s[::-1]
        for i in range(len(s) - 1):
            if s[i : i + 2] in ss:
                return True
        return False
        """
        st = set()
        for x, y in pairwise(s):
            st.add((x, y))
            if (y, x) in st:
                return True
        return False