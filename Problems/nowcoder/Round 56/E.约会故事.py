if 1:
    from itertools import accumulate

    # from functools import cache
    # from math import comb, inf
    import sys

    input = lambda: sys.stdin.readline().strip()
    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y
    lowbit = lambda x: x & -x
    # comb = cache(comb)

    def I():
        return input()

    def II():
        return int(input())

    def LI():
        return list(input().split())

    def MII():
        return map(int, input().split())

    def LII():
        return list(map(int, input().split()))

    MOD = 1_000_000_007


"""

https://ac.nowcoder.com/acm/contest/88392/E

模拟题, 照搬了: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=71050004

"""


def solve():
    n, _ = MII()

    diff = [0] * 1441
    for _ in range(n):
        s, e = LI()

        s1, s2 = s.split(":")
        s1, s2 = int(s1), int(s2)
        s = s1 * 60 + s2

        e1, e2 = e.split(":")
        e1, e2 = int(e1), int(e2)
        e = e1 * 60 + e2

        if s > e:
            s = 0
        diff[s] += 1
        diff[e + 1] -= 1

    diff = list(accumulate(diff))
    for i in range(120, len(diff)):
        diff[i] = 0

    chosen = set(LI())

    q = II()
    outs = []
    for _ in range(q):
        x, y = (int(x) for x in I().split(":"))
        t = x * 60 + y
        a, b = LI()
        c = I()
        if diff[t]:
            if a <= b and (c in chosen):
                outs.append("Winner xqq")
            else:
                outs.append("Joker xqq")
        else:
            outs.append("Loser xqq")

    print("\n".join(outs))


if __name__ == "__main__":
    solve()
