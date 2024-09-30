from typing import List


class Solution:
    def _validStrings(self, n: int) -> List[str]:
        lst = []
        for i in range(pow(2, n)):
            tmp = bin(i)[2:]
            tmp = (n - len(tmp)) * "0" + tmp

            ok = 1
            for i in range(n - 1):
                if tmp[i] == "0" and tmp[i + 1] == "0":
                    ok = 0
                    break

            if ok:
                lst.append(tmp)
        return lst

    # update:
    def validStrings(self, n: int) -> List[str]:
        ans = []
        mask = (1 << n) - 1
        for i in range(1 << n):
            x = mask ^ i
            if (x >> 1) & x == 0:
                ans.append(f"{i:0{n}b}")
        return ans
