from typing import List


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        setA = set()
        setB = set()

        for a, b in paths:
            setB.discard(a)
            if b not in setA:
                setB.add(b)
            setA.add(a)
        return setB.pop()
