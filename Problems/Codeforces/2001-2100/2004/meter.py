from math import gcd

"""
sg 表
"""
N = 500

fmax = lambda x, y: x if x > y else y

mx = 0
sg = [0] * (N + 1)
pos = [[] for _ in range(N + 1)]
for i in range(1, N + 1):
    s = set(sg[i - j] for j in range(1, i + 1) if gcd(i, j) == 1)

    mex = 0
    for v in s:
        if v == mex:
            mex += 1
        else:
            break

    sg[i] = mex

    # print(i, ": ", mex)
    pos[mex].append(i)
    mx = fmax(mx, mex)

for i in range(mx + 1):
    print(i, ": ", *pos[i])

"""
质数个数
"""
N = 1_000_000_0

ok = [1] * (N + 1)
ok[0] = ok[1] = 0
prime = []
for i in range(2, N + 1):
    if not ok[i]:
        continue
    for j in range(i * i, N + 1, i):
        ok[j] = 0

    if ok[i]:
        prime.append(i)

print(len(prime))
