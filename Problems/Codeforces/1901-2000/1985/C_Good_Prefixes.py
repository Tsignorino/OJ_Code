if 1:
    import sys

    input = lambda: sys.stdin.readline().strip()
    max = lambda x, y: x if x > y else y

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))


def solve():
    _ = II()
    lst = LII()

    mx, s, ans = 0, 0, 0
    for _, v in enumerate(lst):
        mx = max(mx, v)
        s += v
        if mx * 2 == s:
            ans += 1

    print(ans)

    pass


if __name__ == "__main__":
    T = II()
    for i in range(T):
        solve()
