from typing import List


class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        d = {"U": -n, "D": n, "L": -1, "R": 1}
        return sum(d[s[0]] for s in commands)

    def finalPositionOfSnake2(self, n: int, commands: List[str]) -> int:
        i = j = 0
        for s in commands:
            match s[0]:
                case "U":
                    i -= 1
                case "D":
                    i += 1
                case "L":
                    j -= 1
                case _:
                    j += 1  # 匹配其他任意值，相当于 switch 中的 default
        return i * n + j
