from typing import List


class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        def check(i:int,sub:str)->bool:
            for j, s in enumerate(arr):
                if j != i and sub in s:
                    return False
            return True
        

        ans = []
        for i, s in enumerate(arr):
            m = len(s)
            res = ""
            for k in range(1, m+1):
                for j in range(k, m+1):
                    t = s[j-k:j]
                    if (not res or t < res) and check(i, t):
                        res = t
                if res:
                    break
            ans.append(res)
        return ans
    
        """
        lst = []

        # 寻找字符串的所有非空子串
        def func(s: str):
            lst = []
            for l in range(1, len(s) + 1):  # 长度为 l
                for i in range(len(s) - l + 1):
                    lst.append(s[i : i + l])
            lst.sort(key=lambda x: (len(x), x))
            # print(lst)
            return lst

        n = len(arr)
        for i, v in enumerate(arr):
            ll = func(v)
            for k, l in enumerate(ll):
                flag1 = False  # 出现重复子串
                cnt = 0
                for j, v2 in enumerate(arr):
                    if i == j:
                        continue
                    if l in v2:
                        flag1 = True
                        break
                    else:
                        cnt += 1

                if flag1:
                    if k == len(ll) - 1:
                        lst.append("")
                    continue

                if j == n - 1 and cnt == n - 1:
                    lst.append(l)
                    break

        return lst
        """
