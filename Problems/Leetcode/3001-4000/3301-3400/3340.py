class Solution:
    def isBalanced(self, num: str) -> bool:
        return sum([int(v) if i % 2 == 0 else -int(v) for i, v in enumerate(num)]) == 0
