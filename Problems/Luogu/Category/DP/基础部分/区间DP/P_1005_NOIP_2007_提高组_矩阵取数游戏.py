if 1:
    import sys

    MOD = 1_000_000_007
    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))


"""
每一行都是独立的，贪心无法解决该行前后元素相同的情况
"""


def solve():
    n, m = MII()
    ans = 0
    for _ in range(n):
        lst = LII()
        dp = [[0] * (m) for _ in range(m + 1)]
        for len in range(1, m + 1):
            for l in range(m - len + 1):
                r = l + len - 1
                dp[l][r] = max(dp[l + 1][r] + lst[l], dp[l][r - 1] + lst[r]) * 2
        ans += dp[0][m - 1]
    print(ans)
    pass


if __name__ == "__main__":
    solve()
