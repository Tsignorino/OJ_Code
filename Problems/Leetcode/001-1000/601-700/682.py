from typing import List

fmax = lambda x, y: x if x > y else y
MOD = 1_000_000_007


class Solution:
    def calPoints(self, ops: List[str]) -> int:
        a = []
        for op in ops:
            if op == "C":
                a.pop()
            elif op == "D":
                a.append(a[-1] * 2)
            elif op == "+":
                a.append(a[-1] + a[-2])
            else:
                a.append(int(op))
        return sum(a)
