import sys
import typing
from heapq import heappop, heappush
from math import inf

input = lambda: sys.stdin.readline().strip()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 998244353


def solve():
    n, m, _ = MII()

    s = [LII() for _ in range(n)]
    t = [LII() for _ in range(m)]

    """
    障碍区间不相连
    """

    i, ans, jump = 0, 0, 1
    has = []
    for l, r in s:
        d = r - l + 1
        while i < m and t[i][0] < l:
            heappush(has, -t[i][1])
            i += 1
        while has and jump <= d:
            jump -= heappop(has)
            ans += 1
        if jump <= d:
            print(-1)
            return
    print(ans)


if __name__ == "__main__":
    for _ in range(II()):
        solve()
