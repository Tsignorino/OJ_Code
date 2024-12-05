# fmt: off
class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        if a == e and (c != e or (d - b) * (d - f) > 0) or \
            b == f and (d != f or (c - a) * (c - e) > 0) or \
            c + d == e + f and (a + b != e + f or (a - c) * (a - e) > 0) or \
            c - d == e - f and (a - b != e - f or (a - c) * (a - e) > 0):
            return 1
        return 2
