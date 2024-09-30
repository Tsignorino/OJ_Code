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
    print(3 if II() == 3 else 2)
    pass


if __name__ == "__main__":
    T = II()
    for i in range(T):
        solve()
