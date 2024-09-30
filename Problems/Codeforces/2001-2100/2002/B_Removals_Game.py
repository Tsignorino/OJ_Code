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


def solve():
    _ = II()
    a = LII()
    b = LII()

    print("Bob" if a == b or a == b[::-1] else "Alice")


if __name__ == "__main__":
    _ = 1
    _ = II()
    for i in range(_):
        solve()
