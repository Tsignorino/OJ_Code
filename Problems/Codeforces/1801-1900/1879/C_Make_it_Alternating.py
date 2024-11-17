import sys

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
    s = I()
    n = len(s)

    ans, cnt = 0, 1
    p = 0
    for i in range(n):
        p += 1
        if i == n - 1 or s[i] != s[i + 1]:
            cnt = cnt * p % MOD
            p = 0
        else:
            ans += 1
            cnt = cnt * ans % MOD
    print(ans, cnt)


if __name__ == "__main__":
    for _ in range(II()):
        solve()
