from typing import List


class Solution:
    def busyStudent(
        self, startTime: List[int], endTime: List[int], queryTime: int
    ) -> int:
        return sum(u <= queryTime <= v for u, v in zip(startTime, endTime))
