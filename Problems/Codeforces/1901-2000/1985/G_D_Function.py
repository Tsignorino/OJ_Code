if 1:
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    MOD = 1_000_000_007

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))


def solve():
    l, r, k = MII()
    print((pow(9 // k + 1, r, MOD) - pow(9 // k + 1, l, MOD)) % MOD)
    pass


if __name__ == "__main__":
    _ = II()
    for i in range(_):
        solve()
