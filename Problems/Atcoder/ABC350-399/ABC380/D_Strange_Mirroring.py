import sys
from string import ascii_lowercase, ascii_uppercase

input = lambda: sys.stdin.readline().strip()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

I = lambda: input()
II = lambda: int(input())
LI = lambda: list(input())
LII = lambda: list(map(int, input().split()))
MII = lambda: map(int, input().split())
LGMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 1_000_000_007

mp = {}
for x in ascii_lowercase:
    mp[x] = x.upper()
for x in ascii_uppercase:
    mp[x] = x.lower()


def solve():
    s = I()
    q = II()

    nums = LGMI()
    ans = []
    for x in nums:
        a, b = divmod(x, len(s))
        if a.bit_count() % 2:
            ans.append(mp[s[b]])
        else:
            ans.append(s[b])
    print(*ans)


if __name__ == "__main__":
    solve()
