class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return "-".join(bin(int(v))[2:] for v in date.split("-"))
