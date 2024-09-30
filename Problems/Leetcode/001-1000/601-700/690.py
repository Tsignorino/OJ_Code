# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


from typing import List


class Solution:
    def getImportance(self, employees: List["Employee"], id: int) -> int:
        d = {e.id: e for e in employees}

        def dfs(i: int) -> int:
            e = d[i]
            return e.importance + sum(dfs(j) for j in e.subordinates)

        return dfs(id)
