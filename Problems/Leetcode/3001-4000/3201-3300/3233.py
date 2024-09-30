import bisect

N = 100000

prime = [1] * (N + 1)
prime[0] = prime[1] = 0
for i in range(2, N + 1):
    if not prime[i]:
        continue
    for j in range(i * i, N + 1, i):
        prime[j] = 0

lst = [i * i for i in range(1, N) if prime[i]]


class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        return r - l + 1 - (bisect.bisect_right(lst, r) - bisect.bisect_left(lst, l))
