if 1:
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    MOD = 1_000_000_007

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))


"""
贪心
"""


def solve():
    n, l, r = MII()
    a = LII()

    # 注意到，符合条件的段没有必要增加
    ans = sum = p = q = 0
    while p < n:
        while q < n and sum < l:
            sum += a[q]
            q += 1
        if l <= sum <= r:
            ans += 1
            p, sum = q, 0  # 跳转
        else:
            sum -= a[p]
            p += 1

    print(ans)
    pass


if __name__ == "__main__":
    _ = 1
    _ = II()
    for i in range(_):
        solve()
