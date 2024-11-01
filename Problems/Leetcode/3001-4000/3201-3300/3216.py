class Solution:
    def getSmallestString(self, s: str) -> str:
        a = list(s)
        for i in range(len(s) - 1):
            if a[i] > a[i + 1] and ord(a[i]) % 2 == ord(a[i + 1]) % 2:
                a[i], a[i + 1] = a[i + 1], a[i]
                break
        return "".join(a)
