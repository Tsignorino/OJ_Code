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
    lst = []
    n, k = MII()
    k += 1
    while n:
        if k <= pow(2, n - 1):
            lst.append(0)
        else:
            lst.append(1)
            k = pow(2, n) - k + 1
        n -= 1
    print(*lst, sep="")
    pass


if __name__ == "__main__":
    solve()
