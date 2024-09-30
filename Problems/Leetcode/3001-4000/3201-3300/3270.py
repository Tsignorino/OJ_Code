class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        ans, p = 0, 1
        while num1 and num2 and num3:
            ans += min(num1 % 10, num2 % 10, num3 % 10) * p
            num1 //= 10
            num2 //= 10
            num3 //= 10
            p *= 10
        return ans
