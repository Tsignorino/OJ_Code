from typing import List


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        SIZE = 8
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c == "R":
                    x0, y0 = i, j
        ans = 0
        for dx, dy in (0, -1), (0, 1), (-1, 0), (1, 0):
            x, y = x0 + dx, y0 + dy
            while 0 <= x < SIZE and 0 <= y < SIZE and board[x][y] == ".":
                x += dx
                y += dy
            if 0 <= x < SIZE and 0 <= y < SIZE and board[x][y] == "p":
                ans += 1
        return ans
