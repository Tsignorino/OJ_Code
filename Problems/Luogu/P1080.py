if 1:
    import sys

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


def solve():
    n = II()
    a, b = MII()

    lst = []
    for _ in range(n):
        l, r = MII()
        lst.append((l, r))

    lst = sorted(lst, key=lambda x: x[0] * x[1])

    pre = a
    mx = 0
    for _, (l, r) in enumerate(lst):
        mx = max(mx, pre // r)
        pre *= l

    print(mx)

    pass


if __name__ == "__main__":
    solve()
