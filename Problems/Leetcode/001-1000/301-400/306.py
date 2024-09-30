class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        def check(a: str, b: str):
            if a.startswith("0") and a != "0" or b.startswith("0") and b != "0":
                return False

            temp = a + b
            a, b = b, str(int(a) + int(b))
            temp += b
            while len(temp) < len(num):
                a, b = b, str(int(a) + int(b))
                temp += b
            return num == temp

        for i in range(1, len(num) - 1):
            for j in range(i):
                if check(num[: j + 1], num[j + 1 : i + 1]):
                    return True
        return False
