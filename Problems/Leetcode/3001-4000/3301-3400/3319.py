# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthLargestPerfectSubtree(self, root: Optional[TreeNode], k: int) -> int:
        lst = []

        def dfs(node=root):
            if not node:
                return 0, True

            l, okl = dfs(node.left)
            r, okr = dfs(node.right)

            if okl and okr and l == r:
                lst.append(l + r + 1)
                return l + r + 1, True
            return l + r + 1, False

        dfs()

        lst.sort()
        if len(lst) < k:
            return -1
        return lst[-k]
