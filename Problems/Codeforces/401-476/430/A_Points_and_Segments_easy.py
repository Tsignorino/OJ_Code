import sys
import typing

input = lambda: sys.stdin.readline().strip()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 1_000_000_007


def solve():
    n, _ = MII()
    nums = LII()

    x = sorted(range(n), key=lambda x: nums[x])
    ans = [0] * n
    for i in range(0, n, 2):
        ans[x[i]] = 1
    print(*ans)


if __name__ == "__main__":
    solve()
