from typing import List


class Solution:
    N = 8
    # 上下左右
    dirs1 = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    # 斜向
    dirs2 = [(1, 1), (-1, 1), (-1, -1), (1, -1)]

    def allMoves(self, x0: int, y0: int, dirs: List[tuple[int, int]]) -> List[tuple[int, int, int, int, int]]:
        moves = [(x0, y0, 0, 0, 0)]
        for dx, dy in dirs:
            x, y = x0 + dx, y0 + dy
            step = 1
            while 0 < x <= self.N and 0 < y <= self.N:
                moves.append((x0, y0, dx, dy, step))
                x += dx
                y += dy
                step += 1
        return moves

    def isValid(self, moves1, moves2) -> bool:
        x1, y1, dx1, dy1, step1 = moves1
        x2, y2, dx2, dy2, step2 = moves2
        for i in range(max(step1, step2)):
            if i < step1:
                x1 += dx1
                y1 += dy1
            if i < step2:
                x2 += dx2
                y2 += dy2
            if x1 == x2 and y1 == y2:
                return False
        return True

    def countCombinations(self, pieces: List[str], positions: List[List[int]]) -> int:
        dirs = {"r": self.dirs1, "b": self.dirs2, "q": self.dirs1 + self.dirs2}
        allMoves = [self.allMoves(x, y, dirs[p[0]]) for p, (x, y) in zip(pieces, positions)]

        n = len(pieces)
        path = [None] * n
        ans = 0

        def dfs(i: int) -> None:
            if i == n:
                nonlocal ans
                ans += 1
                return
            for m1 in allMoves[i]:
                if all(self.isValid(m1, m2) for m2 in path[:i]):
                    path[i] = m1
                    dfs(i + 1)

        dfs(0)
        return ans
