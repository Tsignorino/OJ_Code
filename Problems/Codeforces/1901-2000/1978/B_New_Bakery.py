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
    n, a, b = MII()
    if b <= a:
        print(a * n)
    elif b - a >= n:
        print((b * 2 - n + 1) * n // 2)
    else:
        print((a + b + 1) * (b - a) // 2 + a * (n - b + a))

    pass


if __name__ == "__main__":
    T = II()
    for i in range(T):
        solve()
