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


#  https://codeforces.com/gym/105104/problem/B


def solve():
    x, y, z, k, d = MII()
    if x * y >= z:
        print(0)
        return

    ans = 0
    if x < y:
        x, y = y, x
    if x * k < x + d or x * k == x + d and y * k > y + d:
        x += d
        y *= k
        ans += 1
    while x * y < z:
        x *= k
        y += d
        ans += 1
    print(ans)


if __name__ == "__main__":
    _ = 1
    # _ = II()
    for i in range(_):
        solve()
