class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        return sum(map(ord, coordinate1 + coordinate2)) % 2 == 0
