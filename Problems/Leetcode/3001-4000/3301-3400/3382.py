from bisect import bisect_left
from collections import defaultdict
from itertools import pairwise
from typing import List

# https://leetcode.cn/problems/maximum-area-rectangle-with-point-constraints-ii/solutions/3013907/chi-xian-xun-wen-chi-san-hua-shu-zhuang-gd604


class Fenwick:
    def __init__(self, n: int):
        self.tree = [0] * (n + 1)

    def add(self, i: int):
        while i < len(self.tree):
            self.tree[i] += 1
            i += i & -i

    def pre(self, i: int) -> int:
        res = 0
        while i > 0:
            res += self.tree[i]
            i &= i - 1
        return res

    def query(self, l: int, r: int) -> int:
        return self.pre(r) - self.pre(l - 1)


class Solution:
    def maxRectangleArea(self, xCoord: List[int], yCoord: List[int]) -> int:
        """
        考虑枚举矩形的右上角，二维数点
        """
        X = defaultdict(list)
        Y = defaultdict(list)
        for i, x in enumerate(xCoord):
            y = yCoord[i]
            X[x].append(y)
            Y[y].append(x)

        # 处理每个点正下方的点
        below = {}
        for x, ys in X.items():
            ys.sort()
            for y1, y2 in pairwise(ys):
                below[(x, y2)] = y1

        # 处理每个点正左边的点
        left = {}
        for y, xs in Y.items():
            xs.sort()
            for x1, x2 in pairwise(xs):
                left[(x2, y)] = x1

        # 用于离散化
        xs = sorted(X)
        ys = sorted(Y)

        queries = []
        for x2, list_y in X.items():
            for y1, y2 in pairwise(list_y):
                x1 = left.get((x2, y2), None)
                if x1 is not None and left.get((x2, y1), None) == x1 and below.get((x1, y2), None) == y1:
                    queries.append(
                        (
                            bisect_left(xs, x1),
                            bisect_left(xs, x2),
                            bisect_left(ys, y1),
                            bisect_left(ys, y2),
                            (x2 - x1) * (y2 - y1),
                        )
                    )

        # 离线询问
        qs = [[] for _ in range(len(xs))]
        for i, (x1, x2, y1, y2, _) in enumerate(queries):
            if x1 > 0:
                qs[x1 - 1].append((i, -1, y1, y2))
            qs[x2].append((i, 1, y1, y2))

        # 处理询问
        res = [0] * (len(queries))
        tree = Fenwick(len(ys))
        for i, x in enumerate(xs):
            for y in X[x]:
                tree.add(bisect_left(ys, y) + 1)
            for qi, sign, y1, y2 in qs[i]:
                res[qi] += sign * tree.query(y1 + 1, y2 + 1)

        ans = -1
        for cnt, q in zip(res, queries):
            if cnt == 4:
                ans = max(ans, q[4])
        return ans
