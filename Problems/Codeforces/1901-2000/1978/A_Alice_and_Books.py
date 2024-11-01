if 1:
    import sys

    input = lambda: sys.stdin.readline().strip()

    def I():
        return input().split()

    def II():
        return int(input())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))


def solve():
    _ = I()
    lst = LII()
    print(lst[-1] + max(lst[:-1]))
    
    pass


if __name__ == "__main__":
    T = II()
    for i in range(T):
        solve()
